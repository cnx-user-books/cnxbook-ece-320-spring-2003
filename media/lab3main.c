#include "v:/ece320/54x/dspclib/core.h"  /* Declarations for core file */
void init_filter(void);			  /* Prototypes for assembly functions */
int filter(int sample);
extern int dec_rate;			  /* Default decimation rate is 4 */

main()
{
    int *Rcvptr,*Xmitptr;                 /* pointers to Xmit & Rcv Bufs   */
    int i, sample1, sample2; 
    
    init_filter();			  /* Initialize the filter */
        
    while( 1 )
    {   
    	/* Wait for a new block of samples */
    	WaitAudio(&Rcvptr,&Xmitptr);
    	
    	/* Process a block of samples */
    	for( i = 0; i < BlockLen; i ++ )
    	{
            sample1 = Rcvptr[4*i];		/* Ch1 input sample */
            sample2 = Rcvptr[4*i+2];            /* Ch2 input sample  */
            
            Xmitptr[6*i]   = sample1;		/* First output is input */
	    Xmitptr[6*i+1] = filter(sample1);	/* Secound output is result */
	}        

	i = SerialRX();  	/* Check serial port */
	if( i > 0 )
	    dec_rate = i;	/* Save new decimation rate if we got it */
    }    
}
