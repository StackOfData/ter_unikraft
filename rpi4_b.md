# Unikraft sur RPI4 model B

## KVM on RPI4
https://linuxhint.com/enable_kvm_kernel_module_on_raspberry_pi_os/

## Installation Unikraft
### Installation avec pip
Installation de tout les outils requis
```
apt-get install -y --no-install-recommends \
  build-essential \
  libncurses-dev \
  libyaml-dev \
  flex \
  git \
  wget \
  socat \
  bison \
  unzip \
  uuid-runtime \
  python3 \
  python3-setuptools
```

Installation de Kraft avec pip
```
pip3 install git+https://github.com/unikraft/kraft.git
```

Essaie de l'Installation
```
kraft up -p kvm -m x86_64 -t helloworld helloworld
```

Echec d'Installation
```
r_aarch64_call26 against undefined symbol __getauxval
```
Test d'un programme simple avec la fonction **getauxval()** le programme test fonctionne. Plusieurs recherche, rien n'y fait.

### Installation avec curl depuis le dépôt
```
curl -fsSL https://releases.unikraft.org/linux/gpg | sudo apt-key add -
```
Echec de cette commande 
```
root@rpi4-unik:~# curl -fsSL https://releases.unikraft.org/linux/gpg | apt-key add -
curl: (22) The requested URL returned error: 521
Warning: apt-key is deprecated. Manage keyring files in trusted.gpg.d instead (see apt-key(8)).
gpg: no valid OpenPGP data found.
```
