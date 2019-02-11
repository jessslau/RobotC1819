#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Project Title: A1_1_2 Part 3
Team Members: Josh, Joel, Jessica, Jessica
Date: 2/7/19
Section: N/A


Task Description: control two motors


Pseudocode:

a.Turn the rightMotor on forward at half speed for 5 seconds, and then stop.
b. Turn the leftMotor on in reverse at three-fourths speed for 2.5 seconds, and then stop.
c. Turn both motors on at full power while spinning in the same direction for 7.25 seconds,
and then stop.



*/

task main()
{

                                 
	startMotor(rightMotor, 64); //Spins the motor at half speed for 5 seconds
	wait(5);
	stopMotor(rightMotor);

	startMotor(leftMotor, -96); //Spins the motor at 3/4 speed for 2.5 seconds in the opposite direction
	wait(2.5);
	stopMotor(leftMotor);


	startMotor(rightMotor, 127); //spins both the motors at the same speed for 7.25 seconds
	startMotor(leftMotor, 127);
	wait(7.25);
	stopMotor(rightMotor);
	stopMotor(leftMotor);

	}
