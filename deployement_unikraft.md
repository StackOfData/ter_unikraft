# Test deployement Unikraft

## 1. Installation de KVM
On vérifie si notre processeur peut virtualiser: `egrep '^flags.*(vmx|svm)' /proc/cpuinfo` \
Ou la commande `sudo kvm-ok` peut aussi être utilisé. \
On ajoute l'utilisateur à kvm `sudo adduser $USER kvm` \
On créer notre image `qemu-img create -f qcow2 Documents/VM/kvm_image.img 66` \
Pour lancer l'image avec un fichier boot on utilise `kvm -m 20 -cdrom Documents/VM/debian-11.2.0-amd64-netinst.iso -boot d Documents/VM/kvm_image.img `

## 2. Installation Unikraft
Première commande pour installer tout les packages: `apt-get install -y --no-install-recommends build-essential libncurses-dev libyaml-dev flex git wget socat bison unzip uuid-runtime python3 python3-setuptools;` \
Deuxième commande `pip3 install git+https://github.com/unikraft/kraft.git` si jamais vous avez un problème tel **coockiecutter** qui à la mauvaise version. Utilisé plutôt cette version `pip3 install git+https://github.com/unikraft/kraft.git@staging` \
Mettre à jours la fichier `kraft list update`. Attention il se peut qu'il faille générer un token. Pour ce faire aller sur le site https://github.com/settings/tokens/new, sélectionner **"repo:public_repo"** puis utiliser la commande `export UK_KRAFT_GITHUB_TOKEN=<token>`

### Lien
https://github.com/unikraft/kraft/issues/34 \
https://unikraft.org/getting-started/

### Localisation de l'installation
```
> pip show kraft
...
/home/lucas/.local/lib/python3.8/site-packages
...
```

### Test de Hello World
https://github.com/unikraft/app-helloworld


Les commandes à suivre. Premièrement on va checker notre architecture
```
$ uname -m
```
En fonction de notre architecture on va compiler la bonne
```
$ kraft configure -p -m
```
Personnelement je suis sur une architecture x86_64 du coup j'ai pris `helloworld_kvm-86_64`. J'ai pris kvm pour le faire tourner sur une machine virtuellehttps://wiki.xenproject.org/wiki/Unikraft_Porting_Libraries_Walkthrough. \
Ensuite il faut build. Pour ce faire on peut utiliser 
```
$ kraft build
```
Il peut être intéressant d'explorer le fichier de configuration **.config** avant de build pour vérifier tout les paramètres. \
Ensuite on peut lancer la VM avec :
```
$ sudo qemu-system-x86_64 -kernel "build/app-helloworld-staging_kvm-x86_64" \
                        -enable-kvm \
                        -nographic
```
Si le nom de fichier est faux vous pouvez vérifier dans build la syntaxe correcte. Il se peut que vous n'ayez pas opté pour la deuxième option lors de la récupération du code sur le git. De ce fait le nom peut être différent.

Pour vérifier que la machine virtuelle c'est bien arrêter utiliser la commande:
```
$ virsh list
```
