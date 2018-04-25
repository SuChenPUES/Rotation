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
	int NE0JD = 10000;/*モータ回転数ゼロ判断閾値*/
	int N_MOT_MTC[4] = {10000,-20000,5000,-33000};/*ドライバー側から受信するモーター推定回転数(ケース配列)*/
	
	int NE[4];/*アプリケーション制御用モーター回転数(目標配列)*/
	int F_MOTSTP;/*モータ状態フラグ(1:停止中;0:回転中*/
	
	int i = 0;

	for (i = 0; i < 4; i ++) 

	{
		/*| N_MOT_MTC | ≧ NE0JD の場合*/
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
		
		/*| N_MOT_MTC | ＜ NE0JD の場合*/
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
