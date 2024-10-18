



**********************************"IMPORTANT MSG (PLZ READ THIS BEFORE COMPILING OUR PROJECT**********************************

As you know there are certain marks for bonus( aesthetics, color, music etc) since we are adding music in the project there are certain steps that are need to be done before the project is 
ready to be compiled.

#1
we have submitted the music file (music.wav) along with our project.
plz save it in a folder and copy the path of that folder and paste it in the ""DS Project.cpp"".

#2
go to the solution explorer and right click on the properties.

#3
go to the linker -> input -> additional dependencies.

#4
paste this line ""winmm.lib"". press apply and then ok.

#5
do the same process again two times for debug and release in visual studio.
