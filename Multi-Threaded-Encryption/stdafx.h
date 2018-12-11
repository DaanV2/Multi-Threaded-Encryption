#pragma once

#ifndef Stdafxh_Included
	#define Stdafxh_Included

	#define Lock(object) System::Threading::Monitor::Enter(object);
	#define Unlock(object) System::Threading::Monitor::Exit(object);

	#define Property($Type, $Variable, $Name) property $Type $Name { $Type get() { return this->$Variable; } void set($Type value) { this->$Variable = value; } };

	#define Property_WithEvent($Type, $Variable, $Name, $Event) property $Type $Name { \
		$Type get() { return this->$Variable; }\
		void set($Type value) { this->$Variable = value; this->$Event(this); } };

	#define Property_ReadOnly($Type, $Variable, $Name) property $Type $Name { \
		$Type get() { return this->$Variable; } } };

#endif // !Stdafxh_Included