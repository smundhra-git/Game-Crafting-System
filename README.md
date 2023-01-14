In many role-playing video games, you’re given a crafting system by which you can make new items out
of components you find in the wild. Sometimes the things you craft are themselves components for
more powerful items.
Suppose you find yourself wanting to make the “Killbeast Awesomesword”. The recipe says that it’s
made from:
• 1 Mediocre Sword
• 2 Awesome Charms
The Mediocre Sword is made from:
• 1 Sad Sword
• 3 Iron Ore
(all of which are collectable in the wild)
But each Awesome Charm is made from:
• 2 Boring Charms
• 3 Glowing Fireflies
• 4 Special Sauce.
(all of which are collectible in the wild)
So, if you’re sitting on 8 glowing fireflies, 2 iron ores and one special sauce, what you’d need to collect to
make the Killbeast Awesomesword is:
• 1 Sad Sword
• 1 Iron Ore
• 4 Boring Charms
• 7 Special Sauce
Your task is to create this list of required basic resources, given a set of recipes and a desired object to
make.
Input:
Each input case begins with an integer n (<= 50), the number of objects that exist. A value of n=0
denotes end of input.
There will then be n lines, one for each item. Each line contains a string si (the name of object i) and an
integer qi (<=50), the amount of that object you currently possess. The names of the objects will be
given in alphabetical order, and the strings will not have spaces in them.
Then there will follow n lines, consisting of the recipes for how to make each object. Each line will begin
with an integer c (<=10): the number of components needed to make the item. A value of c=0 means
that the item is found in the wild, a value of c > 0 means it must be crafted.

If c > 0, the line will continue with c pairs of integers and strings. The integer is the number of the
component needed (<= 50), the string is the name of the component (which will be one of the objects
listed previously).
The last line of the input case will be a string from the n object strings, denoting the desired object to
create.
Every item will be created by at most one recipe. Items may appear as components in multiple recipes.
Output:
For each input case it. Output:
Case i:
Obj1 Quant1
...
Objk Quantk
..where each “Obji” is the name of a resource found in the wild. List out the resource names in
alphabetical order, and only list out resources for which the quantity needed is greater than 0.
Sample Input:
8
Awesome_Charm 0
Boring_Charm 0
Glowing_Firefly 8
Iron_Ore 2
Killbeast_Awesomesword 0
Mediocre_Sword 0
Sad_Sword 0
Special_Sauce 1
3 2 Boring_Charm 3 Glowing_Firefly 4 Special_Sauce
0
0
0
2 1 Mediocre_Sword 2 Awesome_Charm
2 1 Sad_Sword 2 Awesome_Charm
0
0
Killbeast_Awesomesword
0
Sample Output:
Case 1:
Boring_Charm 4
Iron_Ore 1
Sad_Sword 1
Special_Sauce 7









The given code is an implementation of a program that takes in an inventory of items and recipes for creating new items, and produces a list of necessary components to produce a desired item.

The input for the program is as follows:

The first line contains an integer n, representing the number of items in the inventory.
The next n lines contain the names and quantities of the items in the inventory.
The next n lines contain the number of components needed to make each item, followed by the names and quantities of the components.
The program uses the Make_Components function to check if the desired item can be made with the current inventory and recipes. If there are not enough of a certain component, the function recursively calls itself to check the components of that component. The output of the program is a list of necessary components to make the desired item.

The program also includes an additional feature of sorting the inventory and combining any duplicate items, as well as a helper function called Find which returns the position of an item in a given vector.

The test cases provided are:

An item is a component in multiple paths
An item that we have is a component in multiple paths and we only use the component once
An item is craftable and used as a component, and we have some of it
We have more than enough of everything we will need
A binary tree with 50 nodes (5.5 levels), each leaf the same components, each requirement 100 items.
Note that the code is written in C++ and requires the iostream and vector libraries. The program can be run by compiling and running the code on a C++ compiler.
