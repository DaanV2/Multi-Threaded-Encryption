#pragma once

#ifndef MultiThreadedEncryption_Crypthographer_Class_Included
#define MultiThreadedEncryption_Crypthographer_Class_Included

#include "stdafx.h"
#include "BlockInfo.h"

using namespace System::Threading::Tasks;

namespace MultiThreadedEncryption
{
	public ref class Crypthographer
	{
	private:
		array<BlockInfo^>^ hBlocks;
		array<Task^>^ hTasks;
		Task^ hReadingTask;
		Task^ hWritingTask;

	public:
		Crypthographer();
	};
}
#endif