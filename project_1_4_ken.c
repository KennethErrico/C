/*
	Ken Errico
	10/25/18
	C - Programming
	Project 1.4

	This program can encypt and decrypt
	a four digit number
*/

//this allows standard I/O functions
#include<stdio.h>

main()
{
	//declare variable
	int chz;
	//instructions for user with choice to encrypt or decrypt
	printf("Input 1 & Press Enter To Encrypt Or,\nInput 2 & Press Enter To Decrypt\n\n");
	scanf_s("%d", &chz);
	//switch decides whether to encrypt or decrypt with faisafe if user enters wrong info
	switch (chz)
	{
	case 1:			//case 1 is for encrypting
		chz = 1;
		//local variables
		int a, b, c, d, stor1, stor2, input, cryp;

		printf("Input A Four Digit Number,\nPress Enter To Encrypt\n\n");
		scanf_s("%d", &input);

		stor1 = input;
		//replaces each digit by adding 7 and getting the remainder after dividing by 10
		a = ((stor1 / 1000 + 7) % 10);
		stor2 = stor1 % 1000;

		b = ((stor2 / 100 + 7) % 10);
		stor1 = stor2 % 100;

		c = ((stor1  / 10 + 7) % 10);
		stor2 = stor1 % 10;

		d = ((stor2 + 7) % 10);
		//swap 1st and third place
		stor1 = a;
		a = c * 1000;
		c = stor1 * 10;
		//swap second and fourth place
		stor1 = b;
		b = d * 100;
		d = stor1 * 1;
		cryp = a + b + c + d;
		printf("\nEncrypted Number Is    %d\n\n", cryp);
		break;

	case 2:						//case 2 is for decrypting
		chz = 2;
		//local variables
		int aa, bb, cc, dd, stor11, stor22, inputd, dcryp;

		printf("Input A Four Digit Number,\nPress Enter To Decrypt\n\n");
		scanf_s("%d", &inputd);

		stor11 = inputd;
		//reverses the previous mathematical process by restoring digits to their original value
		aa = stor11 / 1000;
		stor22 = stor11 % 1000;

		bb = stor22 / 100;
		stor11 = stor22 % 100;

		cc = stor11 / 10;
		stor22 = stor11 % 10;

		dd = stor22;
		//return 1st and third place
		stor11 = ((aa + 3) % 10);
		aa = ((cc + 3) % 10);
		cc = stor11;
		//return second and fourth place
		stor11 = ((bb + 3) % 10);
		bb = ((dd + 3)% 10);
		dd = stor11;
		dcryp = ((aa * 1000) + (bb * 100) + (cc * 10) + dd);
		printf("\nDecrypted Number Is    %d\n\n", dcryp);
		break;

	default:			
		//failsafe to prevent false info
		printf("Stop Trying To Break My Program\n\n");
	}
	//stops screen from exiting when finished executing
	system("pause");
}