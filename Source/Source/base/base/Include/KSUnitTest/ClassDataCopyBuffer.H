
#ifndef KINGSOFT_UNITTEST_CLASSDATACOPYBUFFER_H
#define KINGSOFT_UINITEST_CLASSDATACOPYBUFFER_H

/***************************************************
Filename:ClassDataCopyBuffer.H
CreatedBy: WilsonWei
CreatedOn: 2005��7��29�� 14:11:41.5954528
Description:
�������ר��Ϊ��Ԫ���Է����,���ڲ�����"��"Ϊ��С��λ
���е�Ԫ���Եķ���.��ĳ�Ա���ݱ����ķ����Ƿǳ�Ƶ����
�����.���ÿ����Ĳ��Ժ������Ա�����������ݳ�Ա����
�������ﵽ���ݱȽϵ�Ŀ��,����ȱ©,��Ϊ���ǲ����ܱ�֤
һ����ķ��������޸ĵ������������ݳ�Ա.�������ǲ�����
���ݳ�Աȫƥ��/�Ƚϵķ���.���ڽ���һ������(����)֮ǰ,
�ȰѸ�������б�Ҫ�ĳ�Ա��������һ������,���������(����)
֮��,�ٱ���һ������,�������θ�������ȫ�Ƚ�,���Դﵽ��
���Ŀ��.

����ΪʲôҪʹ���������,���Բ���������������۸�:
http://192.168.27.31/qcweb/pmwiki.php?n=XSJQC.XSJ-QC-SPEC-UnitTestWorkflow

aaaaaaaaaaaa
aaaaaaaaaaaaaaa
***************************************************/


namespace KingsoftUnitTest
{
	/*
	�����ݸ�������,����ֻ�ṩ�����Ժ���ʹ��.
	*/
    class ClassDataCopyBuffer
	{
	public:
		ClassDataCopyBuffer()
		{
			_FirstCopy = 0;
			_SecondCopy = 0;
		}
		~ClassDataCopyBuffer(){
            ReleaseAllCopy();
        }
	protected:
		void* _FirstCopy;
		void* _SecondCopy;
		
	public:
		/*
		// ���õ�һ������
		// @pvTestData Ҫ������������ָ��(_TestData��)
		// @lMemSize Ҫ�������������ڴ��С
		// @Returns: void.
		// @ע��: ���֮ǰ�Ѵ���һ�ݿ���,��ԭ���Ŀ����ᱻ�Զ��ͷ�.
        */
		void SetFirstCopy( const void* pvTestData, long lMemSize )
		{
			ASSERT( pvTestData );
			if( _FirstCopy )
			{
				free(_FirstCopy);
				_FirstCopy = NULL;
			}
			_FirstCopy = malloc( lMemSize );
			memcpy( _FirstCopy, (void*)pvTestData, lMemSize );
		}
		/*
		// ���õڶ�������
		// @pvTestData Ҫ������������ָ��(_TestData��)
		// @lMemSize Ҫ�������������ڴ��С
		// @Returns: void.
		// @ע��: ���֮ǰ�Ѵ���һ�ݿ���,��ԭ���Ŀ����ᱻ�Զ��ͷ�.
        */
		void SetSecondCopy( const void* pvTestData, long lMemSize)
		{
			ASSERT( pvTestData );
			if( _SecondCopy )
			{
				free(_SecondCopy);
				_SecondCopy = NULL;
			}
			_SecondCopy = malloc( lMemSize );
			memcpy( _SecondCopy , (void*)pvTestData, lMemSize );
		}
		/*
		// ��ȡ��һ���࿽��
		// @Returns: void*
        */
		void* GetFirstCopy() const
		{
			return _FirstCopy;
		}
		/*
		// ��ȡ�ڶ����࿽��
		// @Returns: void*
        */
		void* GetSecondCopy() const
		{
			return _SecondCopy;
		}
		/*
		// �ͷŸ����ڴ���Դ
		// @Returns: void.
        */
		void ReleaseAllCopy()
		{
			free(_FirstCopy);
			_FirstCopy = NULL;
			free(_SecondCopy);
			_SecondCopy = NULL;
		}
    };
};
#endif