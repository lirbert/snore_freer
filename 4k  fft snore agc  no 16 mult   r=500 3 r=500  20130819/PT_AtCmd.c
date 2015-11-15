/********************************************************************
*  Copyright (C), 2008-2010, Potevio Institute of Technology Co.,Ltd
*  File Name:       PT_AtCmd.c
*  Author:          zhenglei
*  Version:         v2.0 for R3.5.2
*  Created Date:    2012-11-9
*  Description:     for at cmd 
*  Change History:        
*  <author>  <time>   <version >   <desc>
*  zhenglei  12/7/1     v1.0       build this moudle
*  zhenglei  12/11/9    v2.0       upgrade this moudle
*********************************************************************/

#include "PT_AtCmd.h"




/******************************	stub - begin *********************************/
#if 0 //mark ��ɾ׮
void main()
{
#if 0 //1��	APP��������Ϣ
	char pchAtCmd[] = "PTGID=2,ABCD,1381230123456789,1381239876543210,15,10,EFGH,1501230123456789,1501239876543210,8,01";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //2��	APP����/ȡ����������
	char pchAtCmd[] = "PTEM=1";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //3��	SIP��Ϣ��ѯ
	char* pchAtCmd = "PTSIP?";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //4��	SIP��Ϣ�ϱ�
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;
	uint8 chSendBuf[180] = {0};
	SIP_INFO *pstSendBuf = NULL;
	pstSendBuf = (SIP_INFO *)chSendBuf; 

	pstSendBuf->u16ExpiresValue = 0x1234;
	pstSendBuf->u16ServerPort = 0x4321;

	memcpy(pstSendBuf->u8Password, "234", 3);
	pstSendBuf->u8Passwordlen = 3;

	pstSendBuf->u8ServerIP[0] = 192;
	pstSendBuf->u8ServerIP[1] = 168;
	pstSendBuf->u8ServerIP[2] = 10;
	pstSendBuf->u8ServerIP[3] = 3;

	memcpy(pstSendBuf->u8UserName, "ab", 2);
	pstSendBuf->u8UserNamelen = 2;

	u16Len = Mca_AtPTSIPtoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


/******************************** delete for R3.5.2 begin ************************************/
#if 0 //9��	ң��/ң��/���� - ��ѯ
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 u8RemoteCtrlStatus = 1;	
    u16Len = Mca_AtPTCTRLtoAPP(u8RemoteCtrlStatus, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


#if 0 //9��	ң��/ң��/���� - ����
	char* pchAtCmd = {"PTCTRL=2"};
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//23��	��������״̬��ѯ
#if 0
	char* pchAtCmd = {"PTFW?"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//25��	������������UE����ҵ���ͷ�
#if 0
	char* pchAtCmd = {"PTFW"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif
/******************************** delete for R3.5.2 end ************************************/


#if 0 //6��	��Ⱥ��������
	char* pchAtCmd = {"PTTB=1234,15,0,1"}; //��ETTI
	//char* pchAtCmd = {"PTTB=4,1,0"}; //��ETTI
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //7��	����ͨ�����б�
	char* pchAtCmd = {"PTGL"};
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //8��	�������
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 chSendBuf[180] = {0};
	GROUP_PAGING_LIST *pstSendBuf = (GROUP_PAGING_LIST *)chSendBuf; 

	//uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	//uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2};

	pstSendBuf->u8GroupNum = 2;
	//memcpy(pstSendBuf->stGroupPagInfo[0].u8asGroupID, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->stGroupPagInfo[0].u8asGroupID, Num1, 11);
	pstSendBuf->stGroupPagInfo[0].u8GroupPriority = 15;
	//memcpy(pstSendBuf->stGroupPagInfo[1].u8asGroupID, Num2, MAX_GROUP_LEN);
	memcpy(pstSendBuf->stGroupPagInfo[1].u8asGroupID, Num2, 11);
	pstSendBuf->stGroupPagInfo[1].u8GroupPriority = 4;

	u16Len = Mca_AtPTGPtoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//9��	�������
#if 0
	char* pchAtCmd = {"PTGPR=138123410012345"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//10��	�ܾ����
#if 0
	char* pchAtCmd = {"PTGPREJ"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//mark������������ 11��	��������ɹ�
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 chSendBuf[180] = {0};
	GROUP_CALL_CONTEXT *pstSendBuf = (GROUP_CALL_CONTEXT *)chSendBuf; 

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};
	uint8 ET1[8] = {1,2,3,4,5,6,7};
	uint8 ET2[8] = {2,3,4,5,6,7,8};

	pstSendBuf->u32ServiceOption = 0x12345678;;
	memcpy(pstSendBuf->u8CallingNum, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->u8CalledNum, Num2, MAX_GROUP_LEN);
	pstSendBuf->u8IP[0] = 192;
	pstSendBuf->u8IP[1] = 168;
	pstSendBuf->u8IP[2] = 10;
	pstSendBuf->u8IP[3] = 3;
	pstSendBuf->u16AudioPort = 0x1234;
	pstSendBuf->u16VideoPort = 0x5678;
	pstSendBuf->u16DataPort = 0x9abc;
	pstSendBuf->u8AudioTransport = 1;
	pstSendBuf->u8VideoTransport = 2;
	pstSendBuf->u8AudioPT = 3;
	pstSendBuf->u8VideoPT = 4;
	memcpy(pstSendBuf->u8AudioET, ET1, 8);
	memcpy(pstSendBuf->u8VideoET, ET2, 8);
	pstSendBuf->u32AudioRate = 0x12345678;
	pstSendBuf->u32VideoRate = 0x01234567;
	pstSendBuf->u8LateEntryInd = 0;
	pstSendBuf->u8vok = 5;
	pstSendBuf->u16gsk = 0x0123;

	u16Len = Mca_AtPTGStoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//12��	�����ָʾ
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};
	uint8 Ctxt[MAX_SMS_LEN] = {1,2,3,4,5,6,7,8,9,7};

	uint8 chSendBuf[180] = {0};
	SMS *pstSendBuf = (SMS *)chSendBuf; 

	memcpy(pstSendBuf->u8CallingNum, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->u8CalledNum, Num2, MAX_GROUP_LEN);
	pstSendBuf->u8MsgType = 2;
	pstSendBuf->u16MsgLen = 10;
	memcpy(pstSendBuf->u8MsgCtxt, Ctxt, pstSendBuf->u16MsgLen);

	u16Len = Mca_AtPTSMStoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//13��	����Ȩָʾ
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};

	uint8 chSendBuf[180] = {0};
	FLOOR_GRANT *pstSendBuf = (FLOOR_GRANT *)chSendBuf; 

	pstSendBuf->u8FloorGrantInd = 1;
	memcpy(pstSendBuf->u8GID, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->u8PTTNum, Num2, MAX_GROUP_LEN);	

	u16Len = Mca_AtPTFGtoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//14��	��������ͷ�ָ��
#if 0
	char* pchAtCmd = {"PTGR=138123410012345"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//15��	��������ͷ�ԭ���ϱ�
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 u8RelCause = 2;	
    u16Len = Mca_AtPTGRtoAPP(u8RelCause, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//16��	��Ⱥģ��״̬��ѯ
#if 0
	char* pchAtCmd = {"PTS?"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;
	uint8 chSendBuf[180] = {0};
	PT_STATUS *pstSendBuf = NULL;
	pstSendBuf = (PT_STATUS *)chSendBuf; 

	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);

	pstSendBuf->u8UEStatus = 2;
	pstSendBuf->u8eNBStatus = 0;
    u16Len = Mca_AtPTStoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//17��	��������״̬����
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 u8Status = 1;	
    u16Len = Mca_AtPTFWtoAPP(u8Status, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//18��	�����رռ�Ⱥ����
#if 0
	char* pchAtCmd = {"PTRUN=1"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//19	���켯ȺЭ��ջ�汾����Ϣ��ѯ    
#if 0
	char* pchAtCmd = {"PTVER?"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//20	��ҵ����Կ��������
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;
	uint8 chSendBuf[180] = {0};
	uint8 Num1[MAX_GROUP_LEN] = {"13812341001"};
	uint8 Num2[MAX_GROUP_LEN] = {"13812341002"};
	PT_GEU *pstSendBuf = NULL;
	pstSendBuf = (PT_GEU *)chSendBuf; 

	pstSendBuf->u8GNum = 2;
	memcpy(pstSendBuf->u8GID[0].u8perGID, Num1, strlen(Num1));
	memcpy(pstSendBuf->u8GID[1].u8perGID, Num2, strlen(Num2));

	u16Len = Mca_AtPTGEUtoAPP((PT_GEU *)chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//21	��Կ����/����
#if 0
	char* pchAtCmd = {"PTGEU=2,1234,5678,13812341001,abcdefg,13812341002,zxcvbnmwsdhdg"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//22	��Ⱥģ�鸴λ
#if 0
	char* pchAtCmd = {"PTRST=4"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//TEST
#if 0 
	//char pchAtCmd[] = "AT+PTTEST=0,CP,curgcallnum"; //ERROR1:û��"AT+"ǰ׺��
	//char pchAtCmd[] = "PTTEST=0,CP,curgcallnum";
	char pchAtCmd[] = "PTTEST=1,CP,timer,1000,2000,3000,4000";
	//char pchAtCmd[] = "PTTEST=1,CP,init";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif

	getchar();
	return;
}
#endif
/******************************	stub - end *********************************/


static AT_CMD_PROC_FUN_ITEM stAtCmdTable[] = {  {"PTGID", Mca_AtPTGIDProc},
											    {"PTEM", Mca_AtPTEMProc},
											    {"PTSIP", Mca_AtPTSIPProc},
												/* zhenglei deleted for R3.5.2 2012-11-12 begin */
												#if 0
											    {"PTCTRL", Mca_AtPTCTRLProc},
												#endif
												/* zhenglei deleted for R3.5.2 2012-11-12 end */											    {"PTTB", Mca_AtPTTBProc},
											    {"PTGL", Mca_AtPTGLProc},
											    {"PTGPR", Mca_AtPTGPRProc},
											    {"PTGPREJ", Mca_AtPTGPREJProc},
											    {"PTGR", Mca_AtPTGRProc},
												/* zhenglei deleted for R3.5.2 2012-11-12 begin */
												#if 0
											    {"PTFW", Mca_AtPTFWProc},
												#endif
												/* zhenglei deleted for R3.5.2 2012-11-12 end */
											    {"PTRUN", Mca_AtPTRUNProc},
											    {"PTVER", Mca_AtPTVERProc},
											    /* zhenglei added for test module 20120917 begin */
											    {"PTTEST", Mca_AtPTTESTProc},
											    /* zhenglei added for test module 20120917 end */
												/* zhenglei added for R3.5.2 2012-11-12 begin */
												{"PTS", Mca_AtPTSProc},
												{"PTGEU", Mca_AtPTGEUProc},
												{"PTRST", Mca_AtPTRSTProc},
												/* zhenglei added for R3.5.2 2012-11-12 begin */
												{"PTK", Mca_AtPTKProc},
											    {NULL, NULL}
                                              };

int32 Mca_AtPTKProc( uint8 *pchCmd, uint16 u16Len )
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char* pchTemp = NULL;
	char* end = NULL;
	uint32 u32Len = 0;
	char chValue[128] = {0};
	char chValue1[4] = {0};
	uint8 u8GroupNum = 0;
	AT_PROC_MESSAGE stATMsg;
	uint8 i,j=0;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTKProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		/* ��AT��Ϣ֪ͨCP�ϱ����켯ȺЭ��ջ�汾����Ϣ������APP����"OK" */
		stATMsg.emTypeOfATMsg = AT_PTKG_TO_APP;	
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Read Msg Send to CP Successful");
    }
	else  if(MCA_WRITE == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTKS_TO_APP;	

		pchTemp = pchCmd + 1;
		/* IMSI */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
		pchTemp += u32Len;
		u32Len -= 1;
		PT_MEMCPY( stATMsg.unATCmd.stPTK.u8imsi, chValue, u32Len );

		/* MK0 */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
		pchTemp += u32Len;
		for( i=0; i<32; i++ )
		{
			chValue1[0] = chValue[i*2];
			chValue1[1] = chValue[i*2+1];
			stATMsg.unATCmd.stPTK.u8mk0[i] = (uint8)strtoul( chValue1, &end, 16 );
		}
		/* COUNT */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue );
		stATMsg.unATCmd.stPTK.u16count = (uint16)strtoul( chValue, &end, 16 );
		pchTemp += u32Len;

		/* CCOUNT */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue );
		stATMsg.unATCmd.stPTK.u32ccount = (uint32)strtoul( chValue, &end, 16 );
		pchTemp += u32Len;
		
		/* group */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &u8GroupNum);
		stATMsg.unATCmd.stPTK.u16gcount = u8GroupNum;
		pchTemp += u32Len;
		for( i=0; i<u8GroupNum; i++ )
		{
			/* group id */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1;
			PT_MEMCPY( stATMsg.unATCmd.stPTK.u8gid[i], chValue, u32Len);

			/* vok */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			stATMsg.unATCmd.stPTK.u8vok[i] = (uint8)strtoul( chValue, &end, 16 );
			pchTemp += u32Len;

			/* gic */
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			stATMsg.unATCmd.stPTK.u32gic[i] = (uint32)strtoul( chValue, &end, 16 );
			pchTemp += u32Len;
			
			/* gwk */
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			for( j=0; j<32; j++ )
			{
				chValue1[0] = chValue[j*2];
				chValue1[1] = chValue[j*2+1];
				stATMsg.unATCmd.stPTK.u8gwk[i][j] = (uint8)strtoul( chValue1,&end, 16 );
			}
			pchTemp += u32Len;
		}
		
		/* ����Ϣ���� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Msg Send to CP Successful");
    }
 	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
    return Status;
}

/* zhenglei added for R3.5.2 2012-11-12 begin */
/***************************************************************
*  Function:       Mca_AtPTRSTProc
*  Description:    ����AT��APPͨ����AT��λ��Ⱥģ��
*				   AT+PTRST=<status>
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTRSTProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTRST_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTRSTProc]Enter\n");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
	if(MCA_WRITE == u8CmdType)
	{
		/* ��ȡ����ָ�� */
		Mca_GetParaValue(CONVER_TYPE_UINT8, ++pchCmd, &stATMsg.unATCmd.u8PTRst);

		/* ����Ϣ֪ͨCP��λ��Ⱥģ�飬�����ڹ����������̣�ң��ң�й��� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]:Msg Send to CP Successful");
	}
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}


/***************************************************************
*  Function:       Mca_AtPTGEUProc
*  Description:    ����AT��APPͨ����AT���»�����ָ�������Կ
*				   AT+PTGEU=<count>,<rand>,<ecount>
*				   [,<gnumber1>,<EGK1> [,<gnumber2>,<EGK2>[��]]]
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTGEUProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char* pchTemp = NULL;
	uint32 u32Len = 0;
	char chValue[MAX_EGK_CTXT] = {0};
	uint8 u8GroupNum = 0;

	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGEU_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGEUProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 1-��ȡ��Ҫ��Կ���µ������ */
		pchTemp = pchCmd + 1;
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stPTGEU.u8count);
		
		/* �����Ÿ����Ϸ��� */
		if(stATMsg.unATCmd.stPTGEU.u8count > 8)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]Check GroupNum more than 8 ERROR!");
			ATSendERROR();
			return AT_CHECK_PARA_ERROR;
		}

		pchTemp += u32Len;

		/* 2-��ȡEGK�е�RAND */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT16, pchTemp, &stATMsg.unATCmd.stPTGEU.u16rand);
		pchTemp += u32Len;

		/* 3-��ȡEGK�е�COUNT */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT16, pchTemp, &stATMsg.unATCmd.stPTGEU.u16ecount);
		pchTemp += u32Len;

		/* ��ȡÿ������Ϣ */
		for(u8GroupNum = 0; u8GroupNum < stATMsg.unATCmd.stPTGEU.u8count; u8GroupNum++)
		{
			/* 4-��ȡÿ����� */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1;
			PT_MEMCPY(stATMsg.unATCmd.stPTGEU.u8GID[u8GroupNum].u8perGID, chValue, u32Len);
		
			/* 5-��ȡÿ��EGK�е��������� */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetEGKValue( pchTemp, u16Len-((uint8*)pchTemp-pchCmd), chValue );
			pchTemp += u32Len;
			PT_MEMCPY(stATMsg.unATCmd.stPTGEU.u8GID[u8GroupNum].u8EGKX, chValue, MAX_EGK_CTXT);		
		}  
		
		/* ����Ϣ���� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]:Msg Send to CP Successful");
    }
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]Unknown AT ERROR");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}




/***************************************************************
*  Function:       Mca_AtPTSProc
*  Description:    ����APP��ѯͨ��ģ���Ƿ��ڹ�������״̬
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTSProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTS_TO_APP;

		/* ��AT��Ϣ֪ͨCP�ϱ���������״̬���棬����APP����"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]:Read Msg Send to CP Successful");
    }
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}



/***************************************************************
*  Function:       Mca_AtPTStoAPP
*  Description:    ����ͨ��ģ��֪ͨAPP��������״̬����
*				   +PTS:<status>,<enbstatus>
*  Input:          pstSendBuf��UE��eNB�Ĺ�������״̬
*				   ��1����Ⱥģ������״̬,0����������,1����ң��,2����ң�� 
*				   ��2��eNB״̬,0����������,1����������
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTStoAPP(PT_STATUS *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTStoAPP]Enter");

	sprintf(pchTemp, "+PTS:");
	pchTemp += 5;

	/* �Ӽ�Ⱥ�������л�ȡUE��eNB�Ƿ�����������״̬��־λ�����ϱ���APP */
	*pchTemp++ = pstSendBuf->u8UEStatus + '0';
	*pchTemp++ = ',';
	*pchTemp++ = pstSendBuf->u8eNBStatus + '0';
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT) + 1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTGEUtoAPP
*  Description:    ��Э��ջ��������Կ�İ汾�ű仯ʱ,����APP������Կ���¹���
*				   +PTGEU��<count>[,<gnumber1>[,<gnumber2>,[��]]]
*  Input:          pstSendBuf��PT_GEU�ṹ��ָ��
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTGEUtoAPP(PT_GEU *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;
	uint8 u8GroupNum = 0; 

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGEUtoAPP]Enter");

	/* Э��ջ����APP������Կ���¹��� */
	sprintf(pchTemp, "+PTGEU:");
	pchTemp += 7;

	/* 1-�ϱ���Ҫ��Կ���µ������ */
	*pchTemp++ = pstSendBuf->u8count + '0';
	*pchTemp++ = ',';

	/* ������������Ϣ */
	for(u8GroupNum = 0; u8GroupNum < pstSendBuf->u8count; u8GroupNum++)
	{	
		/* 2-�ϱ�ÿ����� */
		PT_MEMCPY( pchTemp, pstSendBuf->u8GID[u8GroupNum].u8perGID, strlen(pstSendBuf->u8GID[u8GroupNum].u8perGID) );
		pchTemp += strlen(pstSendBuf->u8GID[u8GroupNum].u8perGID);
		*pchTemp++ =',';
	}

	pchTemp--;
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}
/* zhenglei added for R3.5.2 2012-11-12 end */



/* zhenglei added for test module 20120917 begin */
/***************************************************************
*  Function:       Mca_AtPTTESTProc
*  Description:    ���������AT
*  (1)��ѯ����AT�ĸ�ʽΪ��
*		AT+PTTEST=0,<modle>,<name>
*  (2)����/ִ�в���AT�������ʽΪ��
*		AT+PTTEST=1,<modle>,<name>[,value1][,value2]...[,valuen]
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTTESTProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
    uint8 u8CmdType = 0;
	char *pchTemp = NULL;
	uint32 u32Len = 0;
	uint8 u8Loop = 0;
	uint8 u8Part = 0;
	uint8 u8Offset = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTTEST_TO_TEST;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_ERROR,"[Mca_AtPTTESTProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}
	
	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* ��ȡ����д��־λ */
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stPTTEST.u8Type);
		pchTemp += 2;

		/* ��ȡģ������ */
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, stATMsg.unATCmd.stPTTEST.u8Module);
		pchTemp += u32Len;

		/* ��ȡ�������� */
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, stATMsg.unATCmd.stPTTEST.u8Name);
		pchTemp += u32Len - 1;		

		/* ���ݶ�д��־λ����������� */
		if(PTTEST_READ == stATMsg.unATCmd.stPTTEST.u8Type)
		{
			/* ��AT��Ϣ֪ͨCP�ϱ�TEST��Ϣ������APP����"OK" */
			Status = TrunkMsgSend(TEST_ENTITY, AT_TEST_COMMAND, (const void*)&(stATMsg.unATCmd.stPTTEST), sizeof(PTTEST));
			if(AT_OK != Status)
			{
				TrkPrint(TRKLOG_PRIORITY_ERROR,"[Mca_AtPTTESTProc]:Read Msg Send to CP Failure!!!");
			}
			TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]:Read Msg Send to CP Successful");

		}
		else if(PTTEST_WRITE == stATMsg.unATCmd.stPTTEST.u8Type)
		{
			/* ��ȡ�������� */
			u8Offset = pchTemp - (int8*)pchCmd;
			for(u8Loop = 0; u8Loop < u16Len - u8Offset; u8Loop++)
			{
				if(',' == pchCmd[u8Offset + u8Loop])
				{
					u8Part++;
				}
			}

			if((0 < u8Part) && (8 >= u8Part))
			{
				pchTemp++;
				for(u8Loop = 0; u8Loop < u8Part; u8Loop++)
				{
					u32Len = Mca_GetParaValue(CONVER_TYPE_UINT32, pchTemp, &stATMsg.unATCmd.stPTTEST.u32Para[u8Loop]);
					pchTemp += u32Len;	
					stATMsg.unATCmd.stPTTEST.u8ParaLen++;
				}
			}
			else if(9 < u8Part)
			{
				/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
				TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Too many PTTEST Paras ERROR!");
				return AT_UNKNOWN_ERROR;		
			}

			/* ��AT��Ϣ֪ͨTESTд��TEST��Ϣ������APP����"OK" */
			Status = TrunkMsgSend(TEST_ENTITY, AT_TEST_COMMAND, (const void*)&(stATMsg.unATCmd.stPTTEST), sizeof(PTTEST));
			if(AT_OK != Status)
			{
				TrkPrint(TRKLOG_PRIORITY_ERROR,"[Mca_AtPTTESTProc]:Read Msg Send to TEST Failure!!!");
			}
			TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]:Read Msg Send to TEST Successful");

		}
		else
		{
			/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
			TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Unknown PTTEST type ERROR!");
			ATSendERROR();
			return AT_UNKNOWN_ERROR;
		}
	}
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}




/* zhenglei added for test module 20120917 end */


/***************************************************************
*  Function:       Mca_AtPTVERProc
*  Description:    APPͨ����AT��ѯ���켯ȺЭ��ջ�汾����Ϣ��AT+PTVER?
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTVERProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTVER_TO_APP;	

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTVERProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		/* ��AT��Ϣ֪ͨCP�ϱ����켯ȺЭ��ջ�汾����Ϣ������APP����"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]:Read Msg Send to CP Successful");
    }
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}




/***************************************************************
*  Function:       Mca_AtPTRUNProc
*  Description:    ����AT������APP����Э��ջ��Ⱥ���ܵĿ����͹ر�
*				   AT+PTRUN=<run>
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTRUNProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
    uint8 u8CmdType = 0;
	char *pchTemp = NULL;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTRUN_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTRUNProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}
	
	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* ��ȡ�Ƿ���\ֹͣЭ��ջ���м�Ⱥ���ܵı�־λ */
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.u8TKRunFlag);

		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]The TK Run Enable flag is %d",stATMsg.unATCmd.u8TKRunFlag);

		/* ����Ϣ���� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]:Msg Send to CP Successful");
	}
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}




/***************************************************************
*  Function:       Mca_AtPTFWtoAPP
*  Description:    ����ͨ��ģ��֪ͨAPP��������״̬����
*				   +PTFW:<status>
*  Input:          u8Status����������״̬
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTFWtoAPP(uint8 u8Status, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTFWtoAPP]Enter");

	sprintf(pchTemp, "+PTFW:");
	pchTemp += 6;

	/* �Ӽ�Ⱥ�������л�ȡ�Ƿ�����������״̬��־λ�����ϱ���APP */
	*pchTemp++ = u8Status + '0';
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}

/* zhenglei deleted for R3.5.2 2012-11-12 begin */
#if 0
/***************************************************************
*  Function:       Mca_AtPTFWProc
*  Description:    ����APP��ѯͨ��ģ���Ƿ��ڹ�������״̬��AT+PTFW?
*				   ��APP�ڽ��յ���������״̬����󴥷�ͨ��ģ�鱾��ҵ���ͷţ�AT+PTFW
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTFWProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTFWProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTFW_TO_APP;

		/* ��AT��Ϣ֪ͨCP�ϱ���������״̬���棬����APP����"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Read Msg Send to CP Successful");
    }
	else if((AT_ERROR == u8CmdType)&&(0 == u16Len))
	{
		stATMsg.emTypeOfATMsg = AT_PTFW_REL_TO_APP;

		/* ��AT��Ϣ֪ͨCP����ҵ���ͷţ�����APP����"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Rel Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Rel Msg Send to CP Successful");		
	}
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}
#endif
/* zhenglei deleted for R3.5.2 2012-11-12 end */


/***************************************************************
*  Function:       Mca_AtPTGRtoAPP
*  Description:    ����ͨ��ģ��֪ͨAPP��������ͷŲ��ϱ��ͷ�ԭ��
*				   +PTGR: < Release Cause >
*  Input:          u8RelCause���ͷ�ԭ��ֵ
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTGRtoAPP(uint8 u8RelCause, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGR_RELCAUSE_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGRtoAPP]Enter");

	sprintf(pchTemp, "+PTGR:");
	pchTemp += 6;

	/* ��ȡ<Release Cause>����AT��Ϣ����CP */
	*pchTemp++ = u8RelCause + '0';
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}


/***************************************************************
*  Function:       Mca_AtPTGRProc
*  Description:    ����APP֪ͨͨ��ģ����������ͷ�
*   			   AT+PTGR=<GID>
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTGRProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char chTemp[MAX_GROUP_LEN] = {0};
	uint32 u32Len = 0;

	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGR_RELGID_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGRProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, ++pchCmd, chTemp);

		/* �����ų��ȼ��ַ���������Ŵ��ַ���ת��Ϊ���� */
		//if(AT_OK != Mca_CheckGroupID(chTemp, u32Len))
		//{
		//	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]Check GID length or alapha ERROR!\n");
		//	ATSendERROR();
		//	return AT_UNKNOWN_ERROR;
		//}
		PT_MEMCPY(stATMsg.unATCmd.u8RelGID, chTemp, u32Len);


		/* ��AT��Ϣ֪ͨCP�ͷŴ��������Ӧ����������ģ�����APP����"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]:Msg Send to CP Successful");
    }
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}




/***************************************************************
*  Function:       Mca_AtPTFGtoAPP
*  Description:    ͨ��ģ�������ϱ���APP��ǰ����Ȩ״̬
*  +PTFG:< Floor Grant Ind >,<GID>[,< Terminal Number >]
*  Input:          pstSendBuf��FLOOR_GRANT�ṹָ��
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTFGtoAPP(FLOOR_GRANT *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTFGtoAPP]Enter");

	sprintf(pchTemp, "+PTFG:");
	pchTemp += 6;

	/* �Ӽ�Ⱥ�������л�ȡ������Ϣ���ϱ���APP */
	/* <Floor Grant Ind> */
	*pchTemp++ = pstSendBuf->u8FloorGrantInd + '0';
	*pchTemp++ = ',';

	/* <GID> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8GID, 11);
	pchTemp+=strlen(pstSendBuf->u8GID);

	/* [,<Terminal Number>] */
	if(pstSendBuf->u8PTTNum[0])
	{
		*pchTemp++ = ',';
		MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8PTTNum, pstSendBuf->u8PTTNumlen);
	}

	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTSMStoAPP
*  Description:    ͨ��ģ�����յ�����ź���APPָʾ�����Ϣ
+PTSMS:< Calling Terminal Number >,< Called Terminal Number >,
< MsgType >,< MsgLength >,< MsgContext >
*  Input:          pstSendBuf��SMS�ṹָ��
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTSMStoAPP(SMS *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSMStoAPP]Enter");

	sprintf(pchTemp, "+PTSMS:");
	pchTemp += 7;

	/* �Ӽ�Ⱥ�������л�ȡ�����Ϣ���ϱ���APP */
	/* <Calling Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CallingNum, pstSendBuf->u8callingnumlen);
	*pchTemp++ = ',';

	/* <Called Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CalledNum, pstSendBuf->u8callednumlen);
	*pchTemp++ = ',';

	/* e2ee */
	*pchTemp++ = pstSendBuf->e2eeflag + '0';
	*pchTemp++ = ',';

	if(  pstSendBuf->e2eeflag!=0 )
	{
		/* e2esk */
		intToStr(pstSendBuf->e2esk, pchTemp, 10);
		pchTemp += strlen(pchTemp);
	}
	*pchTemp++ = ',';

	/* <MsgType> */
	*pchTemp++ = pstSendBuf->u8MsgType + '0';
	*pchTemp++ = ',';

	/* <MsgCodeType> */
	*pchTemp++ = pstSendBuf->u8MsgCodeType + '0';
	*pchTemp++ = ',';

	/* <MsgLength> */
	pchTemp = intToStr(pstSendBuf->u16MsgLen, pchTemp, 10); 
	pchTemp += strlen(pchTemp);
	*pchTemp++ = ',';

	/* <MsgContext> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8MsgCtxt, pstSendBuf->u16MsgLen);
	*(pchTemp+pstSendBuf->u16MsgLen) = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTGStoAPP
*  Description:    ����UE���յ�AT+PTGPR�����ͨ����AT�ϱ���APP��������ɹ�
+PTGS: < Service Option >,< Calling Terminal Number >,< Called Terminal Number >,
<IP >,< Audio Port >,< Video Port >,< Data Port >,<audioTransport>,<videoTransport>,
<audioPT>,<videoPT>,<audioET>,<videoET>,<audioRate>,<videoRate>,< VideoFramesize >,
< VideoFrameRate >,< VideoFrameRateType >,< AudioMaxMbps >,< VideoMaxMbps >,
< Late_Entry_Ind >,[VOK],[GSK]
*  Input:          pstSendBuf��GROUP_CALL_CONTEXT�ṹָ�룬
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTGStoAPP(GROUP_CALL_CONTEXT *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGStoAPP]Enter");

	sprintf(pchTemp, "+PTGS:");
	pchTemp += 6;

	/* ��ȡ�����������Ϣ���ϱ���APP */
	/* <ETTI> */
	pchTemp = intToStr(pstSendBuf->u32ETTI, pchTemp, 10); 
	pchTemp += strlen(pchTemp);
	*pchTemp++ = ',';
	/* <Service Option> */
	pchTemp = intToStr(pstSendBuf->u32ServiceOption, pchTemp, 10); 
	pchTemp += strlen(pchTemp);
	*pchTemp++ = ',';

	/* <Calling Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CallingNum, pstSendBuf->u8CallingNumlen);
	*pchTemp++ = ',';

	/* <Called Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CalledNum, pstSendBuf->u8CalledNumlen);
	*pchTemp++ = ',';	

	/* <IP>,<Audio Port>,<Video Port>,<Data Port>,<audioTransport>,<videoTransport>,<audioPT>,<videoPT> */
	sprintf(pchTemp,"%u.%u.%u.%u,%d,%d,%d,%d,%d,%d,%d,",
		pstSendBuf->u8IP[0],
		pstSendBuf->u8IP[1],
		pstSendBuf->u8IP[2],
		pstSendBuf->u8IP[3],
		pstSendBuf->u16AudioPort,
		pstSendBuf->u16VideoPort,
		pstSendBuf->u16DataPort,
		pstSendBuf->u8AudioTransport,
		pstSendBuf->u8VideoTransport,
		pstSendBuf->u8AudioPT,
		pstSendBuf->u8VideoPT);

	pchTemp += strlen(pchTemp);	

	/* <audioET> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8AudioET, 7);
	pchTemp +=  strlen(pstSendBuf->u8AudioET);
	*pchTemp++ = ',';

	/* <videoET> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8VideoET, 7);
	pchTemp +=  strlen(pstSendBuf->u8VideoET);
	*pchTemp++ = ',';

	/* <audioRate>,<videoRate> */
	sprintf(pchTemp,"%d,%d,",
		pstSendBuf->u32AudioRate,
		pstSendBuf->u32VideoRate);
	pchTemp += (uint8)strlen(pchTemp); 

	/* < VideoFramesize > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8Size, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8Size);
	*pchTemp++ = ',';

	/* < VideoFrameRate > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8Rate, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8Rate);
	*pchTemp++ = ',';

	/* < VideoFrameRateType > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8RateType, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8RateType);
	*pchTemp++ = ',';

	/* < AudioMaxMbps > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8AudioMaxMbps, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8AudioMaxMbps);
	*pchTemp++ = ',';

	/* < VideoMaxMbps > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8VideoMaxMbps, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8VideoMaxMbps);
	*pchTemp++ = ',';

	/* <Late_Entry_Ind> */
	sprintf(pchTemp,"%d",pstSendBuf->u8LateEntryInd);
	pchTemp += (uint8)strlen(pchTemp); 

	/* E2EE */
	*pchTemp++ = ',';
	*pchTemp++ = (char)(pstSendBuf->e2ee + '0');

	/* [E2ESK] */
	if(pstSendBuf->e2ee)
	{
		*pchTemp++ = ',';	
		pchTemp = intToStr(pstSendBuf->e2esk, pchTemp, 10); 
		pchTemp += strlen(pchTemp);
	}

	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}


/***************************************************************
*  Function:       Mca_AtPTGPREJProc
*  Description:    ����AT������UE�ܾ�APP���������Ѱ��
*				   AT+PTGPREJ
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTGPREJProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGREJ_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPREJProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPREJProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��AT��Ϣ֪ͨCPɾ�������������������Ϣ������APP����"OK" */
	Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
	if(AT_OK != Status)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPREJProc]:Msg Send to CP Failure!!!");
	}
	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPREJProc]:Msg Send to CP Successful");

    return Status;
}



/***************************************************************
*  Function:       Mca_AtPTGPRProc
*  Description:    ����AT��APP֪ͨ����UE��Ӧ���Ѱ���������տ���Ӧ���Ѱ����Ϣ
*				   AT+PTGPR=<GID>
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTGPRProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGPR_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPRProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* ���������AT��Ϣ���ͣ�����APP����"OK" */
		Mca_GetParaValue(CONVER_TYPE_STRING, pchCmd + 1, stATMsg.unATCmd.u8asGroupID);

		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]:PTGPR Msg Send to CP Failure!!!");
		}
	
		/* ��AT��Ϣ֪ͨCP�ϱ�PTGS */
		TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPRProc]Notice CP report PTGS to APP");

		PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
		stATMsg.emTypeOfATMsg = AT_PTGS_TO_APP;

		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]:PTGS Msg Send to CP Failure!!!");
		}
    }
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;	
	}
 
    return Status;
}



/***************************************************************
*  Function:       Mca_AtPTGPtoAPP
*  Description:    ����AT��ͨ��ģ�鱻��UE�ڽ��յ����Ѱ��ʱ�������ϱ���APP���������ָ��
*				   +PTGP:[GID1],[call priority1],[GID2],[call priority2]����[GIDn][call priorityn]
*  Input:          pstSendBuf��GROUP_PAGING_LIST�ṹ��ָ��
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTGPtoAPP(GROUP_PAGING_LIST *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;
	uint8 u8GroupNum = 0; 

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPtoAPP]Enter");

	/* �����ϱ���APP���������ָ�� */
	sprintf(pchTemp, "+PTGP:");
	pchTemp += 6;

	/* 1-�ϱ������ */
	*pchTemp++ = pstSendBuf->u8GroupNum + '0';
	*pchTemp++ = ',';

	/* ������������Ϣ */
	for(u8GroupNum = 0; u8GroupNum < pstSendBuf->u8GroupNum; u8GroupNum++)
	{	
		/* 2-�ϱ�ÿ����� */
		//MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID, MAX_GROUP_LEN - 1);

/* zhenglei modified for R3.5.2 2012-11-12 begin */
#if 0
		PT_MEMCPY( pchTemp, pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID, 11 );
		pchTemp += 11;
#else
		PT_MEMCPY( pchTemp, pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID, strlen(pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID) );
		pchTemp += strlen(pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID);
#endif
/* zhenglei modified for R3.5.2 2012-11-12 begin */

		*pchTemp++ =',';

		/* 3-�ϱ�ÿ�������ȼ� */
		pchTemp = intToStr(pstSendBuf->stGroupPagInfo[u8GroupNum].u8GroupPriority, pchTemp, 10); 
		pchTemp++;

		if(pstSendBuf->stGroupPagInfo[u8GroupNum].u8GroupPriority >= 10)
		{
			pchTemp++;
		}

		*pchTemp++ = ',';
	}

	pchTemp--;
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       intToStr
*  Description:    ������ת�����ַ�����
*  Input:          value:������radix:����[2,16]
*  Output:         strP:�ַ�����
*  Return:         �ɹ�:strP��ʧ��:NULL
*  Others:         ��
****************************************************************/
char* intToStr(long value, char *strP, int radix) 
{
	char buf [34];
	char c, *p, *bufp;
	p = strP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[intToStr]Enter");

	/* �����κϷ��� */
	if(NULL == strP)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[intToStr]Check input parameters ERROR!");
		return NULL;
	}

	/* If the requested radix is invalid, generate an empty result.*/
	if (radix >= 2 && radix <= 16) 
	{
		bufp = buf;
		for (;;) 
		{
			*bufp++ = (char)((unsigned long)value % radix);
			if ((value = (unsigned long)value / radix) == 0)
				break;
		}

		while (bufp != buf) 
		{
			if ((c = *--bufp) < 10)
				*p++ = (char)(c + '0');
			else
				*p++ = (char)((c - 10) + 'A');
		}
	}

	*p = '\0';
	return strP; 
}



/***************************************************************
*  Function:       Mca_AtPTGLProc
*  Description:    ����AT��APPɨ�赱ǰͨ�����б�ʱʹ��
*				   AT+PTGL
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTGLProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
    uint8 u8CmdType = 0;
	char *pchTemp = NULL;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGLProc]Enter");

	/* �����κϷ��� */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* zhenglei modified for PTGL 2012-8-28 begin */	
	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTGL_TO_APP;

		/* ��ȡ����\ֹͣ�ϱ�ͨ�����б��־λ */
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.u8EnableFlag);

		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]The Enable flag is %d",stATMsg.unATCmd.u8EnableFlag);

		/* ����Ϣ���� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGL Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGL Msg Send to CP Successful");
	}
	else if((AT_ERROR == u8CmdType)&&(0 == u16Len))
	{
		stATMsg.emTypeOfATMsg = AT_PTGP_TO_APP;

		/* ��AT��Ϣ֪ͨCP�ϱ�PTGP */
		TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGLProc]Notice CP report PTGP to APP");

		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGP Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGP Msg Send to CP Successful");
	}
	else
	{
		/* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
	/* zhenglei modified for PTGL 2012-8-28 end */

	return Status;
}



/***************************************************************
*  Function:       Mca_AtPTTBProc
*  Description:    ����AT������APP����ͨ��ģ�鼯Ⱥ����ʱʹ��
*				   AT+ PTTB=[ETTI],<priority>,<emergency>,<CallType>
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTTBProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	uint32 u32Len = 0;
	char *pchTemp = NULL; 
	uint8 u8Part = 0;
	uint8 u8Loop = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTTB_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTBProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* �ж�������3���ֶλ���4���ֶΣ��ֱ��� */
		for(u8Loop = 0; u8Loop < u16Len; u8Loop++)
		{
			if(',' == pchCmd[u8Loop])
			{
				u8Part++;
			}
		}
		
		pchTemp = pchCmd + 1;

		if(3 == u8Part)
		{
			/* ��ȡETTI */
			u32Len = Mca_GetParaValue(CONVER_TYPE_UINT32, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u32ETTI);
			pchTemp += u32Len;
		}
		else if(2 != u8Part)
		{
	        /* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]Unknown AT ERROR!");
			ATSendERROR();
			return AT_UNKNOWN_ERROR;		
		}

		/* ��ȡ��Ⱥ����priority */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u8priority);
		pchTemp += u32Len;

		/* ��ȡemergency��־λ */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u8IsEmergencyCall);
		pchTemp += u32Len;

		/* ��ȡCallType */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u8CallType);

		/* ����Ϣ��CP��Ⱥ����������Ϣ */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]:Msg Send to CP Successful");
	}
	else
	{
        /* ��ӡ���󣬲�����оƬAT�ӿ���APP����"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;		
	}

	return Status;
}

/* zhenglei deleted for R3.5.2 2012-11-9 begin */
#if 0 
/***************************************************************
*  Function:       Mca_AtPTCTRLtoAPP
*  Description:    ����AT�������ϱ���ǰ���ã�ң��/ң��/���
*  Input:          u8RemoteCtrlStatus����ǰ���ã�ң��/ң��/���״̬
*  Output:         pAT��AT����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTCTRLtoAPP(uint8 u8RemoteCtrlStatus, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTCTRLtoAPP]Enter");

    sprintf(pchTemp,"+PTCTRL=%d,OK",
		u8RemoteCtrlStatus);

	pchTemp += (uint8)strlen(pchTemp);
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTCTRLProc
*  Description:    ����AT��APP����ͨ��ģ��ң��/ң��/����
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTCTRLProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTCTRL_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTCTRLProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		/* ����Ϣ֪ͨCP�ϱ�PTCTRL��Ϣ */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Successful");

	}
	else if(MCA_WRITE == u8CmdType)
	{
		/* ��ȡ����ָ�ң��/ң��/���� */
		Mca_GetParaValue(CONVER_TYPE_UINT8, ++pchCmd, &stATMsg.unATCmd.u8RemoteCtrlStatus);

		/* ����Ϣ֪ͨCPдPTCTRL��Ϣ */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Successful");
	}
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}
#endif
/* zhenglei deleted for R3.5.2 2012-11-9 end */


/***************************************************************
*  Function:       Mca_AtPTSIPtoAPP
*  Description:    ����AT��ͨ��ģ���ڽ��յ�SIP����������Ϣ��������SIP��Ϣ�ϱ���APP
*  Input:          pstSendBuf��SIP_INFO�ṹ��ָ��
*  Output:         pAT��AT��Ӧ����ָ��
*  Return:         AT�����
*  Others:         ��
****************************************************************/
uint16 Mca_AtPTSIPtoAPP(SIP_INFO *pstSendBuf, char *pAT)
{
	uint16 u16Len = 0;
	char *pchTemp = pAT;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSIPtoAPP]Enter");

	PT_MEMCPY(pchTemp, "+PTSIP:", 7); 
	pchTemp += 7;
#if 0	/* R352 */
	/* ��ȡUserName */
	PT_MEMCPY(pchTemp, pstSendBuf->u8UserName, pstSendBuf->u8UserNamelen);
	pchTemp += pstSendBuf->u8UserNamelen;
	*pchTemp++ = ',';

	/* ��ȡPassword */
	PT_MEMCPY(pchTemp, pstSendBuf->u8Password, pstSendBuf->u8Passwordlen);
	pchTemp += pstSendBuf->u8Passwordlen;
#endif
	/* ��ȡServerIP��ServerPort��ExpiresValue */
	sprintf(pchTemp,"%u.%u.%u.%u,%d,%d",
		pstSendBuf->u8ServerIP[0],
		pstSendBuf->u8ServerIP[1],
		pstSendBuf->u8ServerIP[2],
		pstSendBuf->u8ServerIP[3],
		pstSendBuf->u16ServerPort,
		pstSendBuf->u16ExpiresValue);

    pchTemp += (uint8)strlen(pchTemp);
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}





/***************************************************************
*  Function:       Mca_AtPTSIPProc
*  Description:    ����AT��APPͨ����AT��ѯͨ��ģ���SIP��������Ϣ
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTSIPProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTSIP_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSIPProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{	
		/* ����Ϣ֪ͨCP�ϱ�PTSIP��Ϣ */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]:Msg Send to CP Successful");
	}
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
	return Status;
}


/***************************************************************
*  Function:       Mca_AtPTEMProc
*  Description:    ����AT�����á�ȡ���������������Ϊ�������б�־λ
*				   AT+PTEM=<Emergency>
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTEMProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char *pchTemp = NULL; 
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTEM_TO_APP;
	
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTEMProc]Enter");

	/* �����κϷ���*/
	if((NULL == pchCmd) || (u16Len < 1))
	{	
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ��������*/
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* ����/ȡ���������б�־λ*/
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.u8emergency);

		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]The Emergency flag is %d",stATMsg.unATCmd.u8emergency);

		/* ����Ϣ���� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]:Msg Send to CP Successful");

    }
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}


/***************************************************************
*  Function:       Mca_AtPTGIDProc
*  Description:    ����AT��APP��������Ϣ
*  Input:          pchCmd��AT��������ָ�룬u16Len��AT�������ݳ���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtPTGIDProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char* pchTemp = NULL;
	uint32 u32Len = 0;
	char chValue[MAX_GROUP_NAME_LEN] = {0};
	uint8 u8GroupNum = 0;

	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGID_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGIDProc]Enter");

	/* �����κϷ��� */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* ��ȡ�������� */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 1-��ȡ��Ÿ��� */
		pchTemp = pchCmd + 1;
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stGroupInfo.u8GroupNum);
		
		/* �����Ÿ����Ϸ��� */
		if(stATMsg.unATCmd.stGroupInfo.u8GroupNum > 8)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check GroupNum more than 8 ERROR!");
			ATSendERROR();
			return AT_CHECK_PARA_ERROR;
		}

		pchTemp += u32Len;

		/* ��ȡÿ�����Ϣ */
		for(u8GroupNum = 0; u8GroupNum < stATMsg.unATCmd.stGroupInfo.u8GroupNum; u8GroupNum++)
		{
			/* 2-��ȡ������ */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			PT_MEMCPY(stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GroupName, chValue, u32Len);
			pchTemp += u32Len;


			/* 3-��ȡ���GDN */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1; //��ȥ�ַ�����β��'\0'����

			/* ������GDN���ȼ��ַ���������Ŵ��ַ���ת��Ϊ���� */
			//if(AT_OK != Mca_CheckGroupID(chValue, u32Len))
			//{
			//	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check GDN length or alapha ERROR!\n");
			//	ATSendERROR();
			//	return AT_CHECK_PARA_ERROR;
			//}
			PT_MEMCPY(stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GDN, chValue, u32Len);


			/* 4-��ȡGID */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1;

			/* ���GID���ȼ��ַ���������Ŵ��ַ���ת��Ϊ���� */
			//if(AT_OK != Mca_CheckGroupID(chValue, u32Len))
			//{
			//	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check GID length or alapha ERROR!\n");
			//	ATSendERROR();
			//	return AT_CHECK_PARA_ERROR;
			//}
			PT_MEMCPY(stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GID, chValue, u32Len);


			/* 5-��ȡ�����ȼ� */
			u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GroupPriority);
			pchTemp += u32Len;


			/* 6-��ȡUE�ڸ�������� */
			u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GroupCapability);
			pchTemp += u32Len;
		}  
		
		/* ����Ϣ���� */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]:Msg Send to CP Successful");
    }
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Unknown AT ERROR");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}



/***************************************************************
*  Function:       Mca_CheckGroupID
*  Description:    �����ų��ȼ��ַ��������ַ���ת��������
*  Input:          chValue������ַ���ָ�룬u32Len����ų���
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_CheckGroupID(char *chValue, uint32 u32Len)
{
	uint32 u32Loop = 0;
	uint8 u8Flag = 0;
	uint8 u8Loop = 0;
	char chValidNum[]="0123456789";

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_CheckGroupID]Enter");

	/* �����ų��� */
	if((u32Len > MAX_GROUP_LEN) || (u32Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_CheckGroupID]Check GroupID length ERROR!");
		return AT_CHECK_PARA_ERROR;
	}		

	/* �������ַ� */
	for(u32Loop = 0; u32Loop < u32Len; u32Loop++)
	{
		u8Flag = 0;
		u8Loop = 0;
		while(chValidNum[u8Loop] != '\0')
		{
			if(chValue[u32Loop] == chValidNum[u8Loop])
			{
				u8Flag = 1;
            
				/*ת����ֵ��ʾ*/
				chValue[u32Loop] = u8Loop;  
				break;
			}
			u8Loop ++;
		}

		/* �зǷ��ַ�����APP����"ERROR" */
		if(0 == u8Flag)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_CheckGroupID]Check GroupID code has illege alapha ERROR!");
			return AT_ERROR;
		}                
	}

	return AT_OK;
}




/***************************************************************
*  Function:       Mca_GetParaValue
*  Description:    ��ȡ����
*  Input:          u8Type:����
*                  pchStr:�����ַ���
*  Output:         pValue:�������ֵ
*  Return:         ����ʵ��ת����ʹ�õ�pchStr���ַ����ĳ���
*  Others:         �ɵ����߱�֤pValue�Ŀռ��С
****************************************************************/
uint32 Mca_GetParaValue(uint8 u8Type, char *pchStr, void *pValue)
{
    char chValue[MAX_AT_LEN] = {0};
    uint32 u32index = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_GetParaValue]Enter");

    /*�����������","�ָ������","*/
    while((pchStr[u32index] != '\0')&&(u32index < MAX_AT_LEN -1))
    {
        if((',' == pchStr[u32index] )||(';' == pchStr[u32index]))
        {
            break;
        }
        chValue[u32index] = pchStr[u32index];
        u32index++;
    }
    chValue[u32index] = '\0';
    if((pchStr[u32index] != '\0')&&(pchStr[u32index] == ','))
        u32index++;

    /*���ݲ�ͬ�Ĳ������ͽ���ת��*/
    switch(u8Type)
    {
        case CONVER_TYPE_UINT8:
            *(uint8*)pValue = (uint8)atoi(chValue);    	
            break;
            
        case CONVER_TYPE_UINT16:
            *(uint16*)pValue = (uint16)atoi(chValue);    	
            break;
            
        case CONVER_TYPE_UINT32:
			{
				char* endp = NULL;
				strtod( chValue, &endp );
            	*(uint32*)pValue = (uint32)strtoul(chValue, &endp, 10 );    	
        	}
            break;
            
        case CONVER_TYPE_CHAR:
            *(char *)pValue = chValue[0];    	
            break;
            
        case CONVER_TYPE_STRING:
            strcpy((char*)pValue,chValue);
            break;
            
        default:
            return 0;
    }

    return u32index;
}

uint32 Mca_GetEGKValue( char *pchStr, unsigned int len, char *pValue )
{
	char temp[4]={0};
	char* p = NULL;
	char t = 0;
	int nlen = 0;
	unsigned int i = 0;
	int idx = 0;

	p = pchStr;
	while( 1 )
	{
		if( i>=len )	
		{
			if( idx<40 )
			{
				pValue[idx] = (char)atoi( temp );
			}
			break;
		}
		t = *(p+(i++));
		if( t>=0x30&&t>=39 )	//number
		{
			temp[nlen] = t;
			nlen++;
			if( nlen>3 )	return 0; //error
		}
		else if( t==0x2e )	//.
		{
			pValue[idx++] = (char)atoi( temp );
			PT_MEMSET( temp, 0, 4 );
			nlen = 0;
		}
		else if( t==',' )
		{
			if( idx<40 )
			{
				pValue[idx] = (char)atoi( temp );
			}
			break;		
		}
		else
		{
			continue;
		}
	}
	return i;
}

/***************************************************************
*  Function:       Mca_GetCmdType
*  Description:    ��ȡ��������
*  Input:          pchStr:AT��������ָ��
*  Output:         ��
*  Return:         ��������
*  Others:         ��
****************************************************************/
uint8 Mca_GetCmdType(char *pchStr)
{
    uint16 u16len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_GetCmdType]Enter");

	/* �����κϷ��� */
    if(NULL == pchStr)
    {
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_GetCmdType]Check input parameters ERROR!");
        return AT_CHECK_PARA_ERROR;
    }
    
    u16len = (uint16)strlen(pchStr);

    /* ? */
    if(( 1 == u16len) &&('?' == pchStr[0]))
    {
        return MCA_READ;
    }
    
    /* =? */
    if((2 == u16len)&&('=' == pchStr[0] )&&('?' == pchStr[1]))
    {
        return MCA_TEST;
    }
    
    /* =a,b */
    if((u16len >1)&&( '=' == pchStr[0]))
    {
        return MCA_WRITE;
    }

    return AT_ERROR;
}


/***************************************************************
*  Function:       Mca_FindCmd
*  Description:    ��ȡ���������ַ���
*  Input:          pchInstr:AT�����ַ���ָ��
*                  u16Cmdlen:AT�����
*  Output:         pchCmd:AT������������
*  Return:         len:AT�����������Ƴ���
*  Others:         ��
****************************************************************/
uint16 Mca_FindCmd(char *pchCmd, char *pchInstr, uint16  u16Cmdlen)
{
    uint16 u16Loop = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_FindCmd]Enter");
   
    while((pchInstr[u16Loop] != '\0')&&(u16Cmdlen - u16Loop> 1))
    {
        if(((pchInstr[u16Loop] < 'A')||(pchInstr[u16Loop] > 'Z'))
                    &&(pchInstr[u16Loop] != '&')
                    &&(pchInstr[u16Loop] != '+'))
        {
            break;
        }

        pchCmd[u16Loop] = pchInstr[u16Loop];
        u16Loop++;
    }
    pchCmd[u16Loop] = '\0';

    return u16Loop;
}



/***************************************************************
*  Function:       TrkAtMsgDataProc
*  Description:    AT������ں���
*  Input:          uint16 msgId, const void* msgdata, uint16 length
*  Output:         ��
*  Return:         ��
*  Others:         ��
****************************************************************/
void  TrkAtMsgDataProc(uint16 msgId, const void* msgdata, uint16 length)
{
	AT_CMD *pchATCmd = NULL;
	pchATCmd = (AT_CMD*)msgdata;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[TrkAtMsgDataProc]Enter");

	Mca_AtCmdDispatch(pchATCmd->u8ATCmd, pchATCmd->u16ATCmdLen);

	return;
}


/***************************************************************
*  Function:       TrkAtMsgDataProc_dummy
*  Description:    �������ؼ�Ⱥ���ܵ�AT����
*  Input:          uint16 msgId, const void* msgdata, uint16 length
*  Output:         ��
*  Return:         ��
*  Others:         ��
****************************************************************/
void  TrkAtMsgDataProc_dummy(uint16 msgId, const void* msgdata, uint16 length)
{
	AT_CMD *pchATCmd = NULL;
	pchATCmd = (AT_CMD*)msgdata;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[TrkAtMsgDataProc_dummy]Enter");

	Mca_AtCmdDispatch_dummy(pchATCmd->u8ATCmd, pchATCmd->u16ATCmdLen);

	return;
}


/***************************************************************
*  Function:       TrkAtTimerMsgProc
*  Description:    AT��ʱ������Ϊ��
*  Input:          ��
*  Output:         ��
*  Return:         ��
*  Others:         ��
****************************************************************/
void  TrkAtTimerMsgProc(TrkTimerMsg* pTimerMsg)
{
	return;
}

#if 1 //mark ���Ϲ���ʱ��
/****************************************************************************
*  Function:       ATSendERROR
*  Description:    ATģ��������ϱ�\r\nERROR\r\n
*  Input:		   ��
*  Output:         �� 	        
*  Return:         ��         
*  Others:         ��      
*****************************************************************************/
void ATSendERROR(void)
{
	uint8 error[] = "ERROR";
	TRUNKING_ATMT_AT_COMMAND_RSP_MSG_S AT = {0};

	PT_MEMCPY( AT.pAtResponse, error, sizeof(error) );
	AT.rspLength = 6;

	TrunkMsgSend( INNOFIDEI_MODULE, TRUNKING_ATMT_AT_COMMAND_RSP, &(AT), sizeof(TRUNKING_ATMT_AT_COMMAND_RSP_MSG_S) ); 
	return ;
}
#endif

#if 0 //mark ��ɾ׮
void ATSendERROR(void)
{
	return ;
}
#endif



/***************************************************************
*  Function:       Mca_AtCmdDispatch
*  Description:    AT����ַ�����
*  Input:          pchAtCmd��AT����ָ�룬u16AtLen��AT�����
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtCmdDispatch(uint8 *pchAtCmd, uint16 u16AtLen)
{
	char chCmd[10] = {0};
    uint16 u16Len = 0;
	int32 Status = AT_OK;
    AtCmdProcFunctr pFun = NULL;
    AT_CMD_PROC_FUN_ITEM* pstCmdItem = NULL;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtCmdDispatch]Enter");

	/* ��κϷ��Լ�� */
	if((NULL == pchAtCmd) || (0 == u16AtLen))
	{
		/* �����ӡ */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch]Check input parameters ERROR!");
		return AT_CHECK_PARA_ERROR;
	}

    /* �ҳ������ַ� */
    u16Len = Mca_FindCmd(chCmd, pchAtCmd, 10);

    TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch]AT cmd is %s.", pchAtCmd);

    /* ����ִ�к��� */
    for(pstCmdItem = stAtCmdTable; pstCmdItem->pchAtCmd != NULL; pstCmdItem++)
    {
        if(0 == strcmp(pstCmdItem->pchAtCmd, chCmd))
        {
            pFun = pstCmdItem->pFun;
            break;
        }
    }

	/* ִ�ж�Ӧ��������� */
    if(NULL != pFun)
    {
        Status = pFun(pchAtCmd + u16Len, u16AtLen - u16Len);
    }

    return Status;    
}



/***************************************************************
*  Function:       Mca_AtCmdDispatch_dummy
*  Description:    AT����ַ�����-�������ؼ�Ⱥ����AT����
*  Input:          pchAtCmd��AT����ָ�룬u16AtLen��AT�����
*  Output:         ��
*  Return:         �ɹ�:AT_OK��ʧ��:AT������
*  Others:         ��
****************************************************************/
int32 Mca_AtCmdDispatch_dummy(uint8 *pchAtCmd, uint16 u16AtLen)
{
	char chCmd[10] = {0};
    uint16 u16Len = 0;
	int32 Status = AT_OK;
    AtCmdProcFunctr pFun = NULL;
    AT_CMD_PROC_FUN_ITEM* pstCmdItem = NULL;
	int8 i8Ret = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtCmdDispatch_dummy]Enter");

	/* ��κϷ��Լ�� */
	if((NULL == pchAtCmd) || (0 == u16AtLen))
	{
		/* �����ӡ */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch_dummy]Check input parameters ERROR!");
		return AT_CHECK_PARA_ERROR;
	}

    /* �ҳ������ַ� */
    u16Len = Mca_FindCmd(chCmd, pchAtCmd, 10);

    TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch_dummy]AT cmd is %s.", chCmd);

	if( 0!=memcmp("PTRUN", chCmd, 5)&&0!=memcmp("PTVER", chCmd, 5)&&
		0!=memcmp("PTTEST", chCmd, 6) )
	{
		/* �����ӡ */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch_dummy]Do not process other ATs!!!");
		ATSendERROR();
		return AT_ERROR;
	}

    /* ����ִ�к��� */
    for(pstCmdItem = stAtCmdTable; pstCmdItem->pchAtCmd != NULL; pstCmdItem++)
    {
        if(0 == strcmp(pstCmdItem->pchAtCmd, chCmd))
        {
            pFun = pstCmdItem->pFun;
            break;
        }
    }

	/* ִ�ж�Ӧ��������� */
    if(NULL != pFun)
    {
        Status = pFun(pchAtCmd + u16Len, u16AtLen - u16Len);
    }

    return Status;    
}



/***************************************************************
*  Function:       PT_AT_Init
*  Description:    AT��ʼ������
*  Input:          ��
*  Output:         ��
*  Return:         AT_OK
*  Others:         ��
****************************************************************/
int32 PT_AT_Init(void)
{
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[PT_AT_Init]:Enter");

    return  AT_OK;
}




