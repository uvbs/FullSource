#ifndef _KSTAT_DATA_DEF_H_
#define _KSTAT_DATA_DEF_H_

// ͳ���������Ƴ���
#define STAT_DATA_NAME_LEN      128
#define MAX_UPDATE_STAT_COUNT   8000

#pragma pack(1)
// Server��������Center��ͳ�����ݽṹ
struct KSTAT_DATA_MODIFY
{
    int     nID;
    int64_t nValue;
};
#pragma pack()

#endif