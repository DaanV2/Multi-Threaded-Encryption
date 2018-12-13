#pragma once

#ifndef stdFunctions
#define stdFunctions

	#define Lock(object) System::Threading::Monitor::Enter(object);
	#define Unlock(object) System::Threading::Monitor::Exit(object);

	#define Property($Type, $Variable, $Name) property $Type $Name { $Type get() { return this->$Variable; } void set($Type value) { this->$Variable = value; } };
	#define VirtualProperty($Type, $Variable, $Name) virtual property $Type $Name { virtual $Type get() { return this->$Variable; } virtual void set($Type value) { this->$Variable = value; } };

	#define Property_WithEvent($Type, $Variable, $Name, $Event) property $Type $Name { \
			$Type get() { return this->$Variable; }\
			void set($Type value) { this->$Variable = value; this->$Event(this); } };

	#define Property_ReadOnly($Type, $Variable, $Name) property $Type $Name { \
			$Type get() { return this->$Variable; } } };

#endif