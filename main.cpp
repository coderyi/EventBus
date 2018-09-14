#include "EventBus.hpp"
#include <iostream>

void    foo(EventBus::BaseMessage *i)
{
	EventBus::Message<std::string>  *j = static_cast<EventBus::Message<std::string>*>(i);

	std::cout<<*j->getData() << std::endl;
}

int main()
{
	EventBus::Bus   b;
	b.addListener("hello", foo);
	delete b.sendMessage(new EventBus::Message<std::string>("hello", new std::string("Hello world !")));
	return 0;
}
