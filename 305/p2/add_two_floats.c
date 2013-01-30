/*****************************************************************/
/* File add_two_floats:  asks for two floating point numbers     */
/* then simulates those two floats being added together.         */
/* Displays the result of the simulated and actual adding.       */
/*                                                               */
/* Based on the convert_float_to_bits.c file provided.           */ 
/*****************************************************************/

/* Created by Paul Geromini */

#include <stdio.h>

int main(int argc, char * argv[]) {

union float_32{
        float   floating_value_in_32_bits;
        int     floating_value_as_int;
        struct  sign_exp_mantissa{
                unsigned  mantissa:23;
                unsigned  exponent:8;
                unsigned      sign:1;
        } f_bits;
	struct single_bits{
		unsigned  b0 :1;
		unsigned  b1 :1;
		unsigned  b2 :1;
		unsigned  b3 :1;
		unsigned  b4 :1;
		unsigned  b5 :1;
		unsigned  b6 :1;
		unsigned  b7 :1;
		unsigned  b8 :1;
		unsigned  b9 :1;
		unsigned  b10:1;
		unsigned  b11:1;
		unsigned  b12:1;
		unsigned  b13:1;
		unsigned  b14:1;
		unsigned  b15:1;
		unsigned  b16:1;
		unsigned  b17:1;
		unsigned  b18:1;
		unsigned  b19:1;
		unsigned  b20:1;
		unsigned  b21:1;
		unsigned  b22:1;
		unsigned  b23:1;
		unsigned  b24:1;
		unsigned  b25:1;
		unsigned  b26:1;
		unsigned  b27:1;
		unsigned  b28:1;
		unsigned  b29:1;
		unsigned  b30:1;
		unsigned  b31:1;
	}bit;
 };

 /* Declare two char arrays to hold bits */
 char bit_string_float1[43];
 char bit_string_float2[43]; 
 char bit_string_rslt[43];  

 /* Declare some needed ints */
 int i, shift_rslt, mant_add;
 float hardware_rslt;

 /* Declare two float_32 objects */
 union float_32 float1, float2, float_rslt; 

 for(i=0; i<42; i++){
	bit_string_float1[i] = ' ';
        bit_string_float2[i] = ' ';
        bit_string_rslt[i] = ' '; 
 }

 /* Append null terminating byte to arrays */
 bit_string_float1[42] = '\0';
 bit_string_float2[42] = '\0';
 bit_string_rslt[42] = '\0';

 printf("\nPlease enter a floating point number and new-line: ");
 scanf("%g", &float1.floating_value_in_32_bits);

 printf("\nPlease enter a second floating point number and new-line: ");
 scanf("%g", &float2.floating_value_in_32_bits); 

 bit_string_float1[0] = float1.bit.b31?'1':'0';
 bit_string_float2[0] = float2.bit.b31?'1':'0';

 bit_string_float1[2] = float1.bit.b30?'1':'0';
 bit_string_float2[2] = float2.bit.b30?'1':'0';
 bit_string_float1[3] = float1.bit.b29?'1':'0';
 bit_string_float2[3] = float2.bit.b29?'1':'0';
 bit_string_float1[4] = float1.bit.b28?'1':'0';
 bit_string_float2[4] = float2.bit.b28?'1':'0';
 bit_string_float1[5] = float1.bit.b27?'1':'0';
 bit_string_float2[5] = float2.bit.b27?'1':'0';
 
 bit_string_float1[7] = float1.bit.b26?'1':'0';
 bit_string_float2[7] = float2.bit.b26?'1':'0';
 bit_string_float1[8] = float1.bit.b25?'1':'0';
 bit_string_float2[8] = float2.bit.b25?'1':'0';
 bit_string_float1[9] = float1.bit.b24?'1':'0';
 bit_string_float2[9] = float2.bit.b24?'1':'0';
 bit_string_float1[10] = float1.bit.b23?'1':'0';
 bit_string_float2[10] = float2.bit.b23?'1':'0';

 bit_string_float1[12] = float1.bit.b22?'1':'0';
 bit_string_float2[12] = float2.bit.b22?'1':'0';
 bit_string_float1[13] = float1.bit.b21?'1':'0';
 bit_string_float2[13] = float2.bit.b21?'1':'0';
 bit_string_float1[14] = float1.bit.b20?'1':'0';
 bit_string_float2[14] = float2.bit.b20?'1':'0';

 bit_string_float1[16] = float1.bit.b19?'1':'0';
 bit_string_float2[16] = float2.bit.b19?'1':'0';
 bit_string_float1[17] = float1.bit.b18?'1':'0';
 bit_string_float2[17] = float2.bit.b18?'1':'0';
 bit_string_float1[18] = float1.bit.b17?'1':'0';
 bit_string_float2[18] = float2.bit.b17?'1':'0';
 bit_string_float1[19] = float1.bit.b16?'1':'0';
 bit_string_float2[19] = float2.bit.b16?'1':'0';

 bit_string_float1[21] = float1.bit.b15?'1':'0';
 bit_string_float2[21] = float2.bit.b15?'1':'0';
 bit_string_float1[22] = float1.bit.b14?'1':'0';
 bit_string_float2[22] = float2.bit.b14?'1':'0';
 bit_string_float1[23] = float1.bit.b13?'1':'0';
 bit_string_float2[23] = float2.bit.b13?'1':'0';
 bit_string_float1[24] = float1.bit.b12?'1':'0';
 bit_string_float2[24] = float2.bit.b12?'1':'0';

 bit_string_float1[26] = float1.bit.b11?'1':'0';
 bit_string_float2[26] = float2.bit.b11?'1':'0';
 bit_string_float1[27] = float1.bit.b10?'1':'0';
 bit_string_float2[27] = float2.bit.b10?'1':'0';
 bit_string_float1[28] = float1.bit.b9?'1':'0';
 bit_string_float2[28] = float2.bit.b9?'1':'0';
 bit_string_float1[29] = float1.bit.b8?'1':'0';
 bit_string_float2[29] = float2.bit.b8?'1':'0';
 
 bit_string_float1[31] = float1.bit.b7?'1':'0';
 bit_string_float2[31] = float2.bit.b7?'1':'0';
 bit_string_float1[32] = float1.bit.b6?'1':'0';
 bit_string_float2[32] = float2.bit.b6?'1':'0';
 bit_string_float1[33] = float1.bit.b5?'1':'0';
 bit_string_float2[33] = float2.bit.b5?'1':'0';
 bit_string_float1[34] = float1.bit.b4?'1':'0';
 bit_string_float2[34] = float2.bit.b4?'1':'0';

 bit_string_float1[36] = float1.bit.b3?'1':'0';
 bit_string_float2[36] = float2.bit.b3?'1':'0';
 bit_string_float1[37] = float1.bit.b2?'1':'0';
 bit_string_float2[37] = float2.bit.b2?'1':'0';
 bit_string_float1[38] = float1.bit.b1?'1':'0';
 bit_string_float2[38] = float2.bit.b1?'1':'0';
 bit_string_float1[39] = float1.bit.b0?'1':'0';
 bit_string_float2[39] = float2.bit.b0?'1':'0';

 /* Copy values to ints */
 int mant1 = float1.f_bits.mantissa;
 int mant2 = float2.f_bits.mantissa;

 int exp1 = float1.f_bits.exponent;
 int exp2 = float2.f_bits.exponent;
 
 /* Print the floating values */
 printf("\nThe pattern of floating value %f is: \n%s ", 
  float1.floating_value_in_32_bits, bit_string_float1);

 printf("\nThe original pattern of floating value %f is: \n%s ",
   float2.floating_value_in_32_bits, bit_string_float2);

 /* Check for normalization in both mantissa */ 
 /* Add hidden bit if necesary */
 if(exp1){
   mant1 |= (1<<23);
 }

 if(exp2){
   mant2 |= (1<<23);
 }

 /* If the exponents are different shift to match */
 if((shift_rslt = exp1 - exp2) < 0){
   shift_rslt = -(shift_rslt); /* Change the sign */
   mant1 >>= (shift_rslt > 24 ? 24 : shift_rslt);
   float_rslt.f_bits.exponent = exp2;
 } else {
   mant2 >>= (shift_rslt > 24 ? 24 : shift_rslt);
   float_rslt.f_bits.exponent = exp1;
 }

 /* add the mantissas */
 mant_add = mant1 + mant2;

 /* check for overflow */
 if(mant_add & (1 << 24)){
   mant_add >>= 1;
   float_rslt.f_bits.exponent++;
   float_rslt.f_bits.mantissa = (mant_add & ~(1 << 23));
 } else {
   float_rslt.f_bits.mantissa = (mant_add & ~(1 << 23));
 }

 /* check for infinity */
 if(float_rslt.f_bits.exponent == 0xff){
   float_rslt.f_bits.mantissa = 0;
 }

 /* check sign bit */
 float_rslt.f_bits.sign = 0; /* must be zero, no negative numbers */

 /* compute hardware result */
 hardware_rslt 
  = float1.floating_value_in_32_bits + float2.floating_value_in_32_bits; 

 /* Print results */
 printf("\nEmulated floating result : %f", 
  float_rslt.floating_value_in_32_bits);
 
 printf("\nHardware floating result : %f", hardware_rslt);
 
 /* Create float_rslt bit string */ 
 bit_string_rslt[0] = float_rslt.bit.b31?'1':'0';

 bit_string_rslt[2] = float_rslt.bit.b30?'1':'0';
 bit_string_rslt[3] = float_rslt.bit.b29?'1':'0';
 bit_string_rslt[4] = float_rslt.bit.b28?'1':'0';
 bit_string_rslt[5] = float_rslt.bit.b27?'1':'0';
 
 bit_string_rslt[7] = float_rslt.bit.b26?'1':'0';
 bit_string_rslt[8] = float_rslt.bit.b25?'1':'0';
 bit_string_rslt[9] = float_rslt.bit.b24?'1':'0';
 bit_string_rslt[10] = float_rslt.bit.b23?'1':'0';

 bit_string_rslt[12] = float_rslt.bit.b22?'1':'0';
 bit_string_rslt[13] = float_rslt.bit.b21?'1':'0';
 bit_string_rslt[14] = float_rslt.bit.b20?'1':'0';

 bit_string_rslt[16] = float_rslt.bit.b19?'1':'0';
 bit_string_rslt[17] = float_rslt.bit.b18?'1':'0';
 bit_string_rslt[18] = float_rslt.bit.b17?'1':'0';
 bit_string_rslt[19] = float_rslt.bit.b16?'1':'0';

 bit_string_rslt[21] = float_rslt.bit.b15?'1':'0';
 bit_string_rslt[22] = float_rslt.bit.b14?'1':'0';
 bit_string_rslt[23] = float_rslt.bit.b13?'1':'0';
 bit_string_rslt[24] = float_rslt.bit.b12?'1':'0';

 bit_string_rslt[26] = float_rslt.bit.b11?'1':'0';
 bit_string_rslt[27] = float_rslt.bit.b10?'1':'0';
 bit_string_rslt[28] = float_rslt.bit.b9?'1':'0';
 bit_string_rslt[29] = float_rslt.bit.b8?'1':'0';
 
 bit_string_rslt[31] = float_rslt.bit.b7?'1':'0';
 bit_string_rslt[32] = float_rslt.bit.b6?'1':'0';
 bit_string_rslt[33] = float_rslt.bit.b5?'1':'0';
 bit_string_rslt[34] = float_rslt.bit.b4?'1':'0';

 bit_string_rslt[36] = float_rslt.bit.b3?'1':'0';
 bit_string_rslt[37] = float_rslt.bit.b2?'1':'0';
 bit_string_rslt[38] = float_rslt.bit.b1?'1':'0';
 bit_string_rslt[39] = float_rslt.bit.b0?'1':'0';

 /* Print out the bit string */ 
 printf("\nBit pattern of the result : %s", bit_string_rslt);

 return 0; 
}
