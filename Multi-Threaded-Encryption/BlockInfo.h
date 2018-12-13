#pragma once

#ifndef MultiThreadedEncryption_BlockInfo_Class_Included
#define MultiThreadedEncryption_BlockInfo_Class_Included

#include "stdafx.h"

using namespace System::Threading;

namespace MultiThreadedEncryption
{
	public ref class BlockInfo
	{
	private:
		EventWaitHandle^ ReadingGate;
		EventWaitHandle^ WritingGate;
		Mutex^ Lock;

		array<unsigned char>^ hReadData;
		array<unsigned char>^ hWriteData;
		size_t hStartPosition;
		size_t hLength;
		size_t hID;		
		bool hComplete;

		#ifdef ENVIRONMENT32
		    int hNeed;
		#else
		    long long hNeed;
		#endif

		inline void Initialize();

	public:
		//TODO add description
		BlockInfo();
		//TODO add description
		BlockInfo(size_t nStartPosition, size_t nLength, size_t nID);

		//TODO add description
		Property(size_t, hStartPosition, StartPosition)
		//TODO add description
		Property(size_t, hLength, Length)
		//TODO add description	
		Property(size_t, hID, ID)
		//TODO add description
		property bool IsMarkCompleted
		{
			bool get() { return hNeed == 0 && hComplete; }
		};
			
		#pragma region Begin X

		//TODO add description	
		inline void BeginReading();		
		//TODO add description	
		inline void BeginCrytography();
		//TODO add description
		inline void BeginWriting();

		//TODO add description	
		inline void EndReading();
		//TODO add description	
		inline void EndCrytography();
		//TODO add description	
		inline void EndWriting();

	    #pragma endregion

	   #pragma region Need

		//TODO add description	
		inline void IncreaseNeed();
		//TODO add description	
		inline void DecreaseNeed();		
		//TODO add description
		inline void MarkComplete();

	   #pragma endregion
	};
}

#endif // !MultiThreadedEncryption_BlockInfo_Class_Included