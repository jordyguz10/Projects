/**********************************************************************
 *  PhotoMagic (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Jordy Guzman Alcaraz
Hours to complete assignment: 3 Hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/
The assignment was to use the LFSR we made in ps1a as a random number
generator to encrypt and decrypt an image. I feel that it works correctly
and I believe accomplished this task successfully.

/**********************************************************************
 *  Explain how it works
 **********************************************************************/
The Encryption and Decryption is done in the transform() function. In 
this function, the first thing that is obtained is the size of the image.
This is needed because we need to know how many pixels we have to adjust
to encrypt the image. In the for-loop, each pixel's red, green, and blue
components are modified randomly using the LFSR we made in ps1a. This
is modified randomly based on the LFSR seed that we provide in the command
line arguement. An input and output image for the encryption or decryption 
must be provided in the command line arguement as well.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Class Discord, Class Slides, SFML Website

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No serious problems.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I feel that this assignment was more straight forward than ps1a.
