# Test performance

## Note
Les tests sont basé sur le code fait par Mr Danyl El-Kabir
Je suis reparti du dépôt de l'exemple de Hello world en C. Ma première compilation à échoué à cause des librairies du je n'ai pas ajouté correctement. \
https://wiki.xenproject.org/wiki/Unikraft_Porting_Libraries_Walkthrough lien qui explique le fonctionnement des différents fichiers dans Unikraft. \
http://docs.unikraft.org/developers-external-lib.html lien qui explique l'ajout de librairie externe.


## Conseils

### Unikraft
#### Répertoire important
* `~/.unikraft/unikraft` répertoire contenant le code source d'unikraft
* `/home/<user>/.local/bin/kraft` exec de unikraft (utilisé pour toute les commandes) recommandé de la mettre en variable d'environnement `export kraft=/home/<user>/.local/bin/kraft` pourra être utilisé avec `$kraft`

#### Librairies
- pour ce qui concerne les fichiers ils faut ajouté **vfscore** (peut être ajouté avec `kraft menuconfig`) (ajoute *read, close...*)
- les librairies pour les float et autre standard C peuvent être compris dans `newlib` ou `musl`. Il faut ajouter ces librairies à l'aide de la commande `kraft lib add <nom_de_la_lib>`

#### Commandes pour collecter les performances d'une application
- https://linoxide.com/10-tools-monitor-cpu-performance-usage-linux-command-line/ Un site qui regroupe toutes les commandes principales et essentiel. 
**A voir sysstat**
https://github.com/sysstat/sysstat **sysstat** outil d'évaluation de performance bash.
`pidstat -e ./monApp` c'est le mieux que j'ai trouvé pour le moment.

#### Build
**Pour les test pensé à `rm -r build/` ou `kraft clean` après chaque modification de librairies (ajout, supp)... Sinon le programme va essayer de compiler des dépendances qui ne sont plus nécessaire.**

### Script
#### Script bash
##### time
On peut mesurer le temps d'execution d'un programme à l'aide de l'instruction bash `time`. La sortie de time est mise sur **stderr** du coup si on veut récupérer la valeur il faut utiliser la commande `{ time sleep 1 2> sleep.stderr ; } 2> time.txt` et si on veut ajouter au fichier `2>>`.
##### launch
Le `script3.sh` permet le lancement d'un Unikernel. C'est un script très simpliste.

#### Script python
##### parseTime.py
Permet de parser le résultat obtenue par le script `script_time_measure.sh` décrit ci-dessus. Il converti le temps en miliseconde et enlève les caractères. On obtient ainsi une liste traitable pour un tableau.


### Test
#### Test cpu 
##### Unikraft
*Add lib musl --> `kraft lib add musl` si ajout de lib c standard.*

Use lib:
```
POSIX process-related functions
POSIX user-related funcions
syscall_shim: Syscall shim layer
ukalloc Abstraction for memory allocators
ukallocbbuddy: Binary buddy page allocator
ukargparse: Simple argument parser
ukboot: Unikraft biitstrapping
ukbus Abstraction  for device buses
ukdebug Debbuging and tracing
uklock
uksced
uksglist
uktime
uktimeconv
vfscore
```

Lien utile pour l'ouverture de fichier et la lecture écriture: https://usoc21.unikraft.org/docs/sessions/02-behind-scenes/#06-tutorial--reminder-adding-filesystems-to-an-application
A savoir, la lib pour tout ce qui concerne la lecture/écriture de fichier est dans la lib `vfscore`. Tout les lib standard de C son dans `musl` qu'il faut ajouter à l'aide de la commande `kraft lib add musl`.
Pour le test cpu il est nécessaire de monter une partition dans la VM pour ce faire on utilise la commande suivante
```
qemu-system-x86_64 -fsdev local,id=myid,path=guest_fs,security_model=none -device virtio-9p-pci,fsdev=myid,mount_tag=fs0 -kernel build/06-adding-filesystems_kvm-x86_64 -nographic
```
Avec **myid** étant l'id utilisateur linux, par exemple **lucas** et **path** le chemin d'accès au répertoire connenant le fichier à lire.

Pour plus de détails avec la virtualisation qemu voici la documentation officiel de 9setup:
https://wiki.qemu.org/Documentation/9psetup

#### Test cpu3
Basé sur la suite de fibonachi. Ce test permet de ne pas utiliser l'ouverture de fichier qui peut être technique avec certains Unikernel. De plus, comparé à un calcule de matrice on aura pas de problème page.

#### Test RAM
http://man7.org/linux/man-pages/man1/time.1.html
Commande utilisatble
```
/usr/bin/time -f'%M' ./cpu3
/usr/bin/time -f'%K' ./syscall 
```
Citation depuis le man time
```
%K  Average total (data+stack+text) memory use of the process, in Kbytes.
%M  Maximum resident set size of the process during its lifetime, in Kbytes.
```
Avec ps 
```
ps -o pid,%mem,cmd
```

##### Unikraft
Add lib musl --> `kraft lib add musl`

Use lib:
```
POSIX process-related functions
POSIX user-related funcions
syscall_shim: Syscall shim layer
ukalloc Abstraction for memory allocators
ukallocbbuddy: Binary buddy page allocator
ukargparse: Simple argument parser
ukboot: Unikraft biitstrapping
ukbus Abstraction  for device buses
ukdebug Debbuging and tracing
uklock
uksced
uksglist
uktime
uktimeconv
vfscore
musl
```

#### Test boot
Utilisation de la commande `time`. Peut être executer avec les scripts `scipt_time_measure.sh` qui lance automatiquement les tests. Pour le parsage des résultats il y a un script python `parseTime.py`. Attention les deux scripts sont assez spécifiques. Veillez à respecter le format d'entrer et les noms de fichiers.
##### Unikraft
Use lib:
```
nolibc
POSIX process-related functions
POSIX user-related funcions
syscall_shim: Syscall shim layer
ukalloc Abstraction for memory allocators
ukallocbbuddy: Binary buddy page allocator
ukargparse: Simple argument parser
ukboot: Unikraft biitstrapping
ukbus Abstraction  for device buses
ukdebug Debbuging and tracing
uklock
uksced
uksglist
uktime
uktimeconv
```

