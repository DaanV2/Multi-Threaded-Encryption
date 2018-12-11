#pragma once

#ifndef MultiThreadedEncryption_IBlockInfo_Interface_Included
#define MultiThreadedEncryption_IBlockInfo_Interface_Included

#include "stdafx.h"
using namespace System::IO;

namespace MultiThreadedEncryption
{
	public interface class IBlockInfo
	{
		//TODO add description
		property size_t ID { size_t get(); };

		//TODO add description
		property size_t StartPosition;

		//TODO add description
		property size_t Length;

		//TODO add description
		property bool IsStreamBlock { bool get(); };
		
		//TODO add description
		void Begin_Reading();
		//TODO add description
		void Begin_Crytography();
		//TODO add description
		void Begin_Writing();

		//TODO add description
		void End_Reading();
		//TODO add description
		void End_Crytography();
		//TODO add description
		void End_Writing();

		//TODO add description
		Stream^ GetBaseStream();
	};
}

#endif