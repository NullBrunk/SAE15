<div align="center">
   
# SAE15  

![GitHub top language](https://img.shields.io/github/languages/top/NullBrunk/SAE15?style=for-the-badge)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/NullBrunk/SAE15?style=for-the-badge)
![repo size](https://img.shields.io/github/repo-size/NullBrunk/SAE15?style=for-the-badge)

<a href="https://www.youtube.com/watch?v=FXjJw4VyfFA" target="_blank">
   <img src="https://img.youtube.com/vi/FXjJw4VyfFA/0.jpg">
</a>

</div>

# 🚗 Concept

Ce projet consiste en une suite de classe C++ ainsi qu'un fichier Arduino (.ino) qui organise la logique. Une fois uploadé ce code permettra à votre voiture Arduino de suivre une ligne noir au sol, et de réaliser un 180° (demi-tour) une fois arrivée au bout.

Dans le cadre du projet que nous avions à réaliser, l'Arduino devrais répéter cette action 4 fois, mais vous pouvez évidemment changer cette valeur.

# 💻 Classes
```bash
❯ tree .

SAE15/
├── code.ino
├── include
│   ├── lightsensor.hpp
│   ├── motors.hpp
│   └── utils.hpp
├── README.md
└── src
    ├── lightsensor.cpp
    ├── motors.cpp
    └── utils.cpp

3 directories, 8 files
```

Nous avons choisi d'organiser notre code de façon à avoir d'un coté les .hpp contenant uniquement les signatures des méthodes/fonctions, et de l'autre côté les fichiers sources (.cpp) dans lesquels se trouve la logique.
Enfin, nous avons le fichier main.ino qui est le point d'entrée.
