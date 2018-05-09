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
	/*入力リミット条件*/
	if(DriverRev < (-32767))
	{
		DriverRev = (-32767);
	}
		
	else if(DriverRev > 32767)
	{
		DriverRev = 32767;
	}
		
		
	/*| N_MOT_MTC | ≧ NE0JD の場合*/
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
		
	/*| N_MOT_MTC | ＜ NE0JD の場合*/
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
	int NE0JD = 10000;/*モータ回転数ゼロ判断閾値*/
	int N_MOT_MTC[5] = {10000,-20000,5000,-33000,32000};/*ドライバー側から受信するモーター推定回転数(ケース配列)*/
	
	int NE[5];/*アプリケーション制御用モーター回転数(目標配列)*/
	int F_MOTSTP[5];/*モータ状態フラグ(1:停止中;0:回転中*/

	int i;
	
	/*実行開始*/
	for (i = 0; i < 5; i ++) 
	{
		cal_rotation(&NE[i], &F_MOTSTP[i], NE0JD, N_MOT_MTC[i]);
	}
}
