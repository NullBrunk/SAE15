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

Ce projet consiste en une suite de classe C++ permettant la gestion des moteurs, des capteurs de lumières ainsi que de la LED, et un fichier Arduino (.ino) qui permet l'organisation de la logique. 
<br>
Une fois uploadé ce code permettra à votre voiture Arduino de suivre une ligne noir au sol, et de réaliser un 180° (demi-tour) une fois arrivée au bout de celle-ci, tout en changeant la couleur de sa LED à chaque étape.
Voici le lien d'une <a href="https://www.youtube.com/watch?v=FXjJw4VyfFA" target="_blank">démo</a>.


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

# 🧾 Dépendances
- FastLED : Vous pouvez rapidement l'installer avec le gestionnaire de librairies.
