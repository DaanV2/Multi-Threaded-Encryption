#include "stdafx.h"
#include "BlockInfo.h"

namespace MultiThreadedEncryption
{
#pragma region Constructors 

	inline void BlockInfo::Initialize()
	{
		this->ReadingGate = gcnew EventWaitHandle(false, EventResetMode::ManualReset);
		this->WritingGate = gcnew EventWaitHandle(false, EventResetMode::ManualReset);
		this->Lock = gcnew Mutex();

		this->hReadData = gcnew array<unsigned char>(0);
		this->hWriteData = gcnew array<unsigned char>(0);
		this->hStartPosition = 0;
		this->hLength = 0;
		this->hID = 0;
		this->hComplete = false;
		this->hNeed = 0;
	}

	BlockInfo::BlockInfo()
	{
		Initialize();
	}

	BlockInfo::BlockInfo(size_t nStartPosition, size_t nLength, size_t nID)
	{
		Initialize();
		this->hStartPosition = nStartPosition;
		this->hLength = nLength;
		this->hID = nID;
	}

#pragma endregion

#pragma region Begin X

	inline void BlockInfo::BeginReading()
	{
		this->IncreaseNeed();
		this->Lock->WaitOne();
	}

	inline void BlockInfo::BeginCrytography()
	{
		this->IncreaseNeed();
		this->Lock->WaitOne();
	}

	inline void BlockInfo::BeginWriting()
	{
		this->IncreaseNeed();
		this->Lock->WaitOne();
	}

	inline void BlockInfo::EndReading()
	{
		this->Lock->ReleaseMutex();
		this->DecreaseNeed();
		this->ReadingGate->Set();
	}

	inline void BlockInfo::EndCrytography()
	{
		this->Lock->ReleaseMutex();
		this->DecreaseNeed();
		this->WritingGate->Set();
	}

	inline void BlockInfo::EndWriting()
	{
		this->Lock->ReleaseMutex();
		this->DecreaseNeed();
		this->MarkComplete();
	}

#pragma endregion

#pragma region Need

	inline void BlockInfo::IncreaseNeed()
	{
		System::Threading::Interlocked::Add(this->hNeed, 1);
	}

	inline void BlockInfo::DecreaseNeed()
	{
		System::Threading::Interlocked::Add(this->hNeed, -1);
	}

	inline void BlockInfo::MarkComplete()
	{
		this->hComplete = true;
	}

#pragma endregion
}