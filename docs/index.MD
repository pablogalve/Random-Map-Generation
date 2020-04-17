# Procedural Map Generation

I am [Pablo Galve](https://www.linkedin.com/in/pablogalve), student of the
[Bachelor’s Degree in
Video Games Programming and Development](https://www.citm.upc.edu/ing/estudis/graus-videojocs/) by UPC at CITM). 

This content is generated for the second year’s subject Project 2, under supervision of lecturer
[Marc Garrigó](https://www.linkedin.com/in/mgarrigo).

## Table of Contents
* Dungeon / Outdoors map procedural generation.
* How to make sure areas are reachable.
* Design parameters to meet design intent for each map.

## Intro to the problem
Manually created maps are limited to our budget (both in time and money). We can create awesome levels but we can't design an infinite map as it would consume endless production resources.   

What if we could create a different map in each game? What if we could have endless different combinations?
Well, we can do it with procedural map generation.
Let's see...

### When is it useful to use procedural methodologies instead of doing maps manually?
Well, certainly we should use different methodologies depending on the project requirements.

* Manual
  * If it's a small game.
  * If it needs to follow a defined story/narrative.
  * If you need extreme details.
* Procedural
  * If it's an open-world game.
  * If you want endless different map combinations.
  * If you want every game to be unique.

#### Pros of procedural algorithms
- New challenges and experiences on each game.
- Users can play for years as it's a never ending different experience.
- Maps can be adjust its difficulty based on the player.
- Monetization can be dramatically increased.
### Cons of procedural algorithms
- You can't design it 100% as you want, that's why narrative focused games don't use it.
- It takes time and resources to build.
- Bad for building only 1 level as it's really expensive.

It is usually used for creating the environment, spawning enemies or looting objects.
However, it can be used for anything as you could procedurally generate an entire universe.

We also have to take into account that these methodologies are not trully random but quasi-random and they use content generated beforehand by developers. The computed chooses where to allocate each element of even combine parts of elements to generate more complex objects or assets.

## Different approaches by different games
The most well-known game using procedural map generation is Minecraft by Mojang. 
Civilization V: Randomize layout of its map
Dwarf Fortress and Minecraft entire worlds
Dungeons in Diablo are at least partially procedural generated 
Spore

### Different algorithms
#### Binary space partitioning for Dungeons
This is probably one of the easiest methods to achieve procedural map generation.

Firstly, we have an empty giant room that we'll use to create the map. We name that giant room 1.
We need to divide our available big room in different rooms using binary space partitioning.
Space sizes may be different for each space.
* We create childs 2 and 3 from parent 1.
* We create childs 4 and 5 from parent 2.
* We create childs 6 and 7 from parent 3.
* We create childs 8 and 9 from parent 5.
We divide until we can't divide anymore or until we reach a defined maximum number of spaces.
We'll get something like that:
<img src="/Assets/Binary_space_partitioning_concept__01_dividing_space.PNG" alt="alt text" width="400" height="200">

Then, once we have the space divided we generate separated rooms inside each space.
In order to that we generate a room of the space' size but leaving a margin in order to leave some empty spaces without rooms.
For example, we can achieve that by giving a 10% margin between space wall and room wall.

<img src="https://github.com/pablogalve/Random-Map-Generation/blob/master/Assets/Binary_space_partitioning_concept__02_rooms.PNG" alt="alt text" width="400" height="200">

Finally, we create corridors to connect all the rooms and make sure that the entire map is reachable.
In order to achieve that, we start with the youngest child and we connect chils from the same parent.
* 8 and 9
* 4 and 5. But 4 is composed by 8 and 9, so we create a corridor between 5 and (8 or 9, can be choosed randomly).
* 6 and 7
* 2 and 3. Both 2 and 3 are groups of rooms so we need to connect one room from each group.
<img src="https://github.com/pablogalve/Random-Map-Generation/blob/master/Assets/Binary_space_partitioning_concept__03_corridors.PNG" alt="alt text" width="400" height="200">

You can find more information about this method in this !["Sunny Valley Studio" video series on youtube.](https://www.youtube.com/watch?v=VnqN0v95jtU)

#### Perlin Noise


![The Happie Cat](https://www.youtube.com/watch?v=JdYkcrW8FBg)

#### Interpretive 
Used by Spore
<img src="Interpretive_spore_01.PNG" alt="alt text" width="400" height="200">
<img src="Interpretive_spore_02.PNG" alt="alt text" width="400" height="200">
<img src="Interpretive_motion.PNG" alt="alt text" width="400" height="200">

## Description in detail for the selected approach
We'll be using Perlin Noise for this tutorial.

![Coding Challenge #10 2D Terrain Generation using Perlin Noise](https://www.youtube.com/watch?v=jv6YT9pPIHw)

## Links to more documentation

## TODOs and Solution inside the repository as VS p rojects

## Optional Homework for practicing

## Explanation of any other improvements on the system



# Notes
get a different seed every game, put into the formula and get the result

Noise patterns generated randomly by some math formula
Perlin noise to make it smoother
Ridged multifractal noise

Assets are not stored on your machine as they are generated every time using the seed

### Problem
You have generated mathematically unique, but...
They are not perceived as unique
10.000 bowls of oatmeal problem
It's sometimes a problemes, sometimes not.
For example in a forest if trees are similar or equal it's not a problem
