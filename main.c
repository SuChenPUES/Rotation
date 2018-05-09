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

void cal_rotation(int *MotRev, int *MotFlag, int ThresholdRev, int DriverRev);

void main(void);

void cal_rotation(int *MotRev, int *MotFlag, int ThresholdRev, int DriverRev)
{
	/*���̓��~�b�g����*/
	if(DriverRev < (-32767))
	{
		DriverRev = (-32767);
	}
		
	else if(DriverRev > 32767)
	{
		DriverRev = 32767;
	}
		
		
	/*| N_MOT_MTC | �� NE0JD �̏ꍇ*/
	if (abs(DriverRev) > ThresholdRev || abs(DriverRev) == ThresholdRev)
	{
		*MotRev = DriverRev;
			
		if (*MotRev < (-32767))
		{
			*MotRev = -32767;
		}
		else if (*MotRev > 32767)
		{
			*MotRev = 32767;
		}
			
		*MotFlag = 0;
			
	}
		
	/*| N_MOT_MTC | �� NE0JD �̏ꍇ*/
	if (abs(DriverRev) < ThresholdRev)
	{
		*MotRev = 0;
			
		if (*MotRev < (-32767))
		{
			*MotRev = -32767;
		}
		else if (*MotRev > 32767)
		{
			*MotRev = 32767;
		}
			
		*MotFlag = 1;
			
	}
}

void main(void)
{
	int NE0JD = 10000;/*���[�^��]���[�����f臒l*/
	int N_MOT_MTC[5] = {10000,-20000,5000,-33000,32000};/*�h���C�o�[�������M���郂�[�^�[�����]��(�P�[�X�z��)*/
	
	int NE[5];/*�A�v���P�[�V��������p���[�^�[��]��(�ڕW�z��)*/
	int F_MOTSTP[5];/*���[�^��ԃt���O(1:��~��;0:��]��*/

	int i;
	
	/*���s�J�n*/
	for (i = 0; i < 5; i ++) 
	{
		cal_rotation(&NE[i], &F_MOTSTP[i], NE0JD, N_MOT_MTC[i]);
	}
}
