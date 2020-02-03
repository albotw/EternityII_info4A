* Implémentation totale des méthodes
* IA
* UX
* UI (Police unicode et code ANSI)


### Notes:
* #### mapping 2D / 1D
    * i = x + width * y;
    * x = i % width;
    * y = i / width;
* ### mapping 3D / 1D
    * i = x + width * y + width * height * z;
    * x = i % width;
    * y = (i / width) % height;
    * z = i / (width / height);



  B    A    C    D  
A # CC # DD # BB # A
  D    B    A    C