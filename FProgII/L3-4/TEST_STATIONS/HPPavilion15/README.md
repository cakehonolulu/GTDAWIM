### Kernel (uname -a)

Linux CS3003NS 5.16.9-051609-generic #202202110934 SMP PREEMPT Fri Feb 11 09:59:18 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux

### Distro (lsb_release -a)

No LSB modules are available.

Distributor ID:	Ubuntu

Description:	Ubuntu Jammy Jellyfish (development branch)

Release:	22.04

Codename:	jammy


### Compilers

#### clang (clang -v)

Ubuntu clang version 15.0.0-++20220317042121+c354f13e6995-1~exp1~20220317042220.53

Target: x86_64-pc-linux-gnu

Thread model: posix

InstalledDir: /usr/bin

Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/10

Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11

Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11

Candidate multilib: .;@m64

Candidate multilib: 32;@m32

Candidate multilib: x32;@mx32

Selected multilib: .;@m64


#### gcc (gcc -v)

Using built-in specs.

COLLECT_GCC=gcc

COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper

OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa

OFFLOAD_TARGET_DEFAULT=1

Target: x86_64-linux-gnu

Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.2.0-18ubuntu1' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-XWYfV6/gcc-11-11.2.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-11-XWYfV6/gcc-11-11.2.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2

Thread model: posix

Supported LTO compression algorithms: zlib zstd

gcc version 11.2.0 (Ubuntu 11.2.0-18ubuntu1)


#### mingw (x86_64-w64-mingw32-gcc -v)

Using built-in specs.

COLLECT_GCC=x86_64-w64-mingw32-gcc

COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-w64-mingw32/10-win32/lto-wrapper

Target: x86_64-w64-mingw32

Configured with: ../../src/configure --build=x86_64-linux-gnu --prefix=/usr --includedir='/usr/include' --mandir='/usr/share/man' --infodir='/usr/share/info' --sysconfdir=/etc --localstatedir=/var --disable-option-checking --disable-silent-rules --libdir='/usr/lib/x86_64-linux-gnu' --libexecdir='/usr/lib/x86_64-linux-gnu' --disable-maintainer-mode --disable-dependency-tracking --prefix=/usr --enable-shared --enable-static --disable-multilib --with-system-zlib --libexecdir=/usr/lib --without-included-gettext --libdir=/usr/lib --enable-libstdcxx-time=yes --with-tune=generic --with-headers --enable-version-specific-runtime-libs --enable-fully-dynamic-string --enable-libgomp --enable-languages=c,c++,fortran,objc,obj-c++,ada --enable-lto --enable-threads=win32 --program-suffix=-win32 --program-prefix=x86_64-w64-mingw32- --target=x86_64-w64-mingw32 --with-as=/usr/bin/x86_64-w64-mingw32-as --with-ld=/usr/bin/x86_64-w64-mingw32-ld --enable-libatomic --enable-libstdcxx-filesystem-ts=yes --enable-dependency-tracking SED=/bin/sed

Thread model: win32

Supported LTO compression algorithms: zlib

gcc version 10-win32 20220113 (GCC)