/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :Mon, Oct 24, 2016                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

void main(void);

void main(void)
{
	int NE0JD = 10000;/*���[�^��]���[�����f臒l*/
	int N_MOT_MTC[5] = {10000,-20000,5000,-33000,32000};/*�h���C�o�[�������M���郂�[�^�[�����]��(�P�[�X�z��)*/
	
	int NE[5];/*�A�v���P�[�V��������p���[�^�[��]��(�ڕW�z��)*/
	int F_MOTSTP;/*���[�^��ԃt���O(1:��~��;0:��]��*/
	
	int i = 0;

	for (i = 0; i < 5; i ++) 

	{
		/*���̓��~�b�g����*/
		if(N_MOT_MTC[i] < (-32767))
		{
			N_MOT_MTC[i] = (-32767);
		}
		
		else if(N_MOT_MTC[i] > 32767)
		{
			N_MOT_MTC[i] = 32767;
		}
		
		
		/*| N_MOT_MTC | �� NE0JD �̏ꍇ*/
		if (abs(N_MOT_MTC[i]) > NE0JD || abs(N_MOT_MTC[i]) == NE0JD)
		{
			NE[i] = N_MOT_MTC[i];
			
			if (NE[i] < (-32767))
			{
				NE[i] = -32767;
			}
			else if (NE[i] > 32767)
			{
				NE[i] = 32767;
			}
			
			F_MOTSTP = 0;
			
		}
		
		/*| N_MOT_MTC | �� NE0JD �̏ꍇ*/
		if (abs(N_MOT_MTC[i]) < NE0JD)
		{
			NE[i] = 0;
			
			if (NE[i] < (-32767))
			{
				NE[i]=-32767;
			}
			else if (NE[i] > 32767)
			{
				NE[i] = 32767;
			}
			
			F_MOTSTP = 1;
			
		}
		
	}
}
