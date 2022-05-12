# Installation HermiTux

## Documentation
https://github.com/ssrg-vt/hermitux-kernel/blob/master/README-hermitcore.md
https://ssrg-vt.github.io/hermitux/
https://github.com/ssrg-vt/hermitux

## Command Line Install
Package
```
sudo apt update
sudo apt install git build-essential cmake nasm apt-transport-https wget \
	libgmp-dev bsdmainutils libseccomp-dev python libelf-dev
```
HermitCore toolchain installed in `/opt/hermit`

### Build
Clone repo + retrieve sub module
```
git clone https://github.com/ssrg-vt/hermitux
cd hermitux
git submodule init && git submodule update
```
Compile everything
```
make
```

### Test installe
```
cd apps/npb/is
# let's compile it as a static binary:
gcc *.c -o is -static
# let's launch it with HermiTux:
sudo HERMIT_ISLE=uhyve HERMIT_TUX=1 ../../../hermitux-kernel/prefix/bin/proxy \
	../../../hermitux-kernel/prefix/x86_64-hermit/extra/tests/hermitux is

# Now let's try with a dynamically linked program:
gcc *.c -o is-dyn
# We can run it by having hermitux execute the dynamic linux loader:
sudo HERMIT_ISLE=uhyve HERMIT_TUX=1 \
	../../../hermitux-kernel/prefix/bin/proxy \
	../../../hermitux-kernel/prefix/x86_64-hermit/extra/tests/hermitux \
	/lib64/ld-linux-x86-64.so.2 ./is-dyn
```

## Test Hermitux
J'ai utilisé les tests créer par M.El-kabir. Le dépôt d'Hermitux ce situe dans le répertoire **~/Documents/hermitux/** on peut compiler à la main à l'aide de `gcc myApp.c -o myApp -static`. (Attention sans le static le programme ne fonctionnera pas). \
Ensuite il faut lancé le programme d'Hermitux avec la commande suivante:
```
HERMIT_ISLE=uhyve HERMIT_TUX=1 \
                ~/Documents/hermitux/hermitux-kernel/prefix/bin/proxy \
                ~/Documents/hermitux/hermitux-kernel/prefix/x86_64-hermit/extra/tests/hermitux cpu\
```

### Mesure image
https://github.com/ssrg-vt/hermitux/wiki/Aarch64-support
Celon cette page de documentation le noyau Hermitux se situe dans `~/Documents/hermitux/hermitux-kernel/prefix/x86_64-hermit/extra/tests`