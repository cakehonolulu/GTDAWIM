.bss
    .align 2
    avg: .space 4
    mod: .space 4

.text
		.align 2
		.arm

//.global normalitzar_temperatures
.global avgmaxmin_city
.global avgmaxmin_month
.extern div_mod

.include "Q12.i"
.include "avgmaxmintemp.i"

/*

    r0: t_cityinfo vinfo[]
    r1: Q12 ttemp[][12]
    r2: unsigned short num_cities

    typedef struct
    {	
        char *name;			// nom de la ciutat
        char scale;			// escala utilitzada ('C': Celsius, 'F': Fahrenheit)
    } t_cityinfo;
*/
/*
normalitzar_temperatures:
    push {r1 - r12, lr}
    # r5: i = 0
    mov r5, #0

    # r6: j = 0
    mov r6, #0

.fori:
    mov r7, r5
    mov r7, r7, lsl #3
    mov r8, r0
    add r7, r8, r7
    ldrb r7, [r7, #4]
    cmp r7, #'F'
    bne .cont
.forj:
    # dir(i,j) = Base + (i * NC + j) * T
    mul r10, r5, r2
    add r10, r6
    mov r11, #4
    mul r10, r11, r10

    push {r0}

    ldr r0, [r1, r10]
    bl Fahrenheit2Celsius
    str r0, [r1, r10]
    
    pop {r0}

    add r6, r6, #1
    cmp r6, #12
    blo .forj

.cont:
    add r5, r5, #1
    cmp r5, r2
    blo .fori

    pop {r1 - r12, pc}
*/

/*

    r0: Q12 ttemp[][12]
    r1: unsigned short nrows
    r2: unsigned short id_city
    r3: t_maxmin *mmres

    typedef struct
    {	
        Q12 tmin_C;				// temperatura m�nima, en graus Celsius
        Q12 tmax_C;				// temperatura m�xima, en graus Celsius
        Q12 tmin_F;				// temperatura m�nima, en graus Fahrenheit
        Q12 tmax_F;				// temperatura m�xima, en graus Fahrenheit
        unsigned short id_min;	// �ndex temperatura m�nima
        unsigned short id_max; 	// �ndex temperatura m�xima
    } t_maxmin; 

*/
avgmaxmin_city:
    push {r1 - r12, lr}

    /*
        dir(i,j) = Base + (i * NC + j) * T
    */

    # r12 = sizeof(val) = int = 4 bytes
    mov r12, #4

    # r11 = NC = 12
    mov r11, #12

    # j = 0 so we don't need to specify anything else

    # i * NC, save in r5
    mul r5, r2, r11

    # r5 * T; save in r5
    mul r5, r12, r5

    # load the value inside ttemp[id_city][0]
    ldr r4, [r0, r5]

    /*
        r4 = avg
        r5 = tvar
        r6 = max
        r7 = min
        r8 = idmin
        r9 = idmax
    */
    mov r6, r4
    mov r7, r6

    # idmin
    mov r8, #0
    # idmax
    mov r9, #0

    # r10 = i = 1
    mov r10, #1

.for:
    mul r5, r2, r11
    add r5, r10
    mul r5, r12, r5

    # tvar = ttemp[id_city][i];
    ldr r5, [r0, r5]

    # avg += tvar;
    add r4, r4, r5

    cmp r5, r6

    blo .continue

    mov r6, r5
    mov r9, r10

.continue:
    cmp r5, r7
    bhi .continue2
    mov r7, r5
    mov r8, r10

.continue2:

    add  r10, r10, #1
    cmp  r10, #11
    ble .for

    # 0x15555556 = Integer part of ((2^32 / 12) + 1)
    ldr r10, =0x15555556

    # R6 contains the avg /= 12 value
    umull r5, r6, r4, r10

    mov r1, #MM_TMAXC
    str r6, [r3, r1]

    mov r1, #MM_TMINC
    str r7, [r3, r1]

    mov r0, r7

    bl Celsius2Fahrenheit

    mov r1, #MM_TMINF
    str r0, [r3, r1]

    mov r0, r6

    bl Celsius2Fahrenheit

    mov r1, #MM_TMAXF
    str r0, [r3, r1]

    mov r1, #MM_IDMIN
    str r8, [r3, r1]

    mov r1, #MM_IDMAX
    str r9, [r3, r1]

    mov r0, r6

    pop {r1 - r12, pc}

/*

    r0: Q12 ttemp[][12]
    r1: unsigned short nrows
    r2: unsigned short id_month
    r3: t_maxmin *mmres

    typedef struct
    {	
        Q12 tmin_C;				// temperatura m�nima, en graus Celsius
        Q12 tmax_C;				// temperatura m�xima, en graus Celsius
        Q12 tmin_F;				// temperatura m�nima, en graus Fahrenheit
        Q12 tmax_F;				// temperatura m�xima, en graus Fahrenheit
        unsigned short id_min;	// �ndex temperatura m�nima
        unsigned short id_max; 	// �ndex temperatura m�xima
    } t_maxmin; 

*/
avgmaxmin_month:
    push {r1 - r12, lr}

    /*
        dir(i,j) = Base + (i * NC + j) * T
    */

    # r12 = sizeof(val) = int = 4 bytes
    mov r12, #4

    # j * T; save in r5
    mul r11, r2, r12

    # load the value inside ttemp[id_city][0]
    ldr r6, =avg
    ldr r4, [r0, r11]
    
    str r4, [r6]
    /*
        r4 = avg
        r5 = tvar
        r6 = max
        r7 = min
        r8 = idmin
        r9 = idmax
    */
    mov r6, r4
    mov r7, r4

    # r11 = i = 1
    mov r11, #1

.while:
    cmp r11, r1 
    beq .endwhile

    mov r10, #12
    mul r5, r11, r10
    add r5, r2, r5
    mov r10, #4
    mul r5, r10, r5

    # tvar = ttemp[i][id_month]
    ldr r5, [r0, r5]

    # avg += tvar
    push {r0}
    add r4, r5, r4
    ldr r0, =avg
    str r4, [r0]
    pop {r0}

    cmp r5, r6

    blo .ifcont

    mov r6, r5
    mov r9, r11

.ifcont:
    cmp r5, r7
    bhi .ifcont2
    mov r7, r5
    mov r8, r11

.ifcont2:

    add r11, r11, #1
    b .while

.endwhile:
    # avgNeg = 0
    mov r11, #0

    # avg < 0?
    cmp r4, #0
    bhi .higheravg

    # if avg  < 0, avgNeg = 1
    # avgNeg = (avg < 0) = 1
    mov r11, #1

.higheravg:
    # avgNeg = 1?
    cmp r11, #1
    bne .skipternary

    # Negative number -avg
    # Load the mask val. to the register
	ldr r12, =MASK_SIGN
		
	# Toggle sign bit
	orr r5, r12, r4

.skipternary:
    # tvar = +-avg
    mov r5, r4

    # call to div_mod(r0: tvar; r1: r1; r2: &avg, r3: &mod)
    push {r0, r3}
    mov r0, r5

    ldr r2, =avg
    ldr r3, =mod

    bl div_mod

    pop {r0, r3}
    
    # if (avgNeg)
    cmp r11, #1

    bne .skipavgnegation

    ldr r12, =MASK_SIGN
		
	# Toggle sign bit
	orr r4, r12, r4

.skipavgnegation:

    mov r12, #0
    str r7, [r3, r12]

    mov r12, #4
    str r6, [r3, r12]

    mov r0, r7
    bl Celsius2Fahrenheit

    mov r12, #8
    str r0, [r3, r12]

    mov r0, r6
    bl Celsius2Fahrenheit

    mov r12, #12
    str r0, [r3, r12]

    mov r12, #16
    str r8, [r3, r12]

    mov r12, #18
    str r9, [r3, r12]

    ldr r1, =avg
    ldr r0, [r1]

    pop {r1 - r12, pc}
