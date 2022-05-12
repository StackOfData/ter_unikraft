# Installation Nanos

## Commande
Installation
```
curl https://ops.city/get.sh -sSfL | sh
```

Vérification de l'installation 
```
ops version
```
Si la commande échoue soit fermer et rouvrir un terminal. Soit déconnecter sa session puis la reconnecter.

Installer dans `/home/<user>/.ops/`
Les builds vont dans `/home/<user>/.ops/images/monApp.img`

## Utilisation
Compiler le code C avec gcc. Puis l'exécuter avec `ops run app`. Où app est le nom du binaire.

## Détails
Nano os est basé sur OSv qui utilise comme hyperviseur Firecracker (hyperviseur spécialisé pour les Unikernels)

## Liens
https://nanos.org/thebook
https://nanovms.gitbook.io/ops/bhyve


