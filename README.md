# Alizarin
A hybrid between a dual stick shooter and a classic ARPG in the style of Diablo. Main sources of inspiration include Diablo 3, Mass Effect, Path of Exile and Warframe.

The name "Alizarin" is actually from a menacing-sounding red color pigment, which would accurately describe the main enemies of the game. The creatures that threaten humanity (name TBD) are monstrosities of metal, flesh, and gleaming red crystal. After all, what is a Diablo clone without a little body horror?

# Goals for Gameplay

Controls will resemble a dual stick, working with keyboard and mouse and eventually controller. For keyboard, WASD controls movement, left and right click will be primary and secondary fire, and 1234 will be mapped to abilities. A dodge roll will likely be mapped to Spacebar. All of these controls have pretty obvious analogues on a controller, but UI development will be more complex.

Eventually, players should be able to customize their characters through skills found as random items in the world (such as modules that would attach to armor or weapons) and investment into talent trees based around Combat Tactics (weapons and maneuvers), Technology Mastery (high-tech gadgets and companions), and Spooky Space Magic (paranormal, skills like gravity manipulation, summoning meteors, lightning etc, name TBD). Each of the three categories would have two tiers and you would be able to unlock 3 / 6 tiers for each character. Unlocking a tier should grant a skill option by itself, such as the ability to deploy a robotic sentry for investing into Technology. Each tree will be mostly passive bonuses which should give the player interesting decisions for what skills and loot are worth using.

Alizarin will feature dungeon crawling with different objective twists. The goal is to have a robust level generator that can place connected objectives as setpieces within a visually seamless dungeon. An example dungeon may have a boss inside a room that can only be accessed by finding and defeating two elite enemies in smaller boss rooms. Another dungeon may involve defending a point from waves of enemies, unlocking an area with an item to bring to an extraction point. Objectives like these could be combined in any order, such that one must be done before the other.

Unlike Diablo, I will likely restrict changing equipment to periods in a hub between dungeon crawls. Loot will of course be gathered and compared in the dungeon, but each one should feel like a short, self-contined experience. This is also because, as a shooter, the primary and secondary skills (left and right click) will be tied to the weapon you are weilding. Carrying extra weapons for swapping might be a skill for unlocking tiers of Combat Tactics. Also, unlike Diablo, I will likely not have an overworld but a series of levels that you can travel to via dropship.

# Currently Developing

The player is wielding a nondescript weapon. I am trying to make a class hierarchy that will make for an easily extended weapon that will allow for a lot of variety in gameplay.

The current level generator is extremely naive and mostly tests my method of placing prefabricated tiles seamlessly. My next step is to make larger objective rooms, scatter them throughout the map, pathfind between them, add noise to the paths, then fill in those paths while making more random branches using my current method.



