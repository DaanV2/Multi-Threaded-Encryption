#pragma once

#ifndef MultiThreadedEncryption_BlockInfo_Class_Included
#define MultiThreadedEncryption_BlockInfo_Class_Included

#include "stdafx.h"

namespace MultiThreadedEncryption
{
	public ref class BlockInfo
	{
		size_t hStartPosition;
		size_t hLength;

	public:
		BlockInfo();

		//TODO add description
		Property(size_t, hStartPosition, StartPosition)

		//TODO add description
		Property(size_t, hLength, Length)


	};
}

#endif // !MultiThreadedEncryption_BlockInfo_Class_Included