using namespace std;

struct Agent {
	int ID;
	Agent* nextAgent;
};

/*
There are two societies. 
Society heads alert "next" agents by sending a message when they learn important information. 
Each agent only knows his/her unique ID and the location of the next agent.
Both societies believe one of their agents is receiving messages from the other, but do not know which one.
Given the location of each society head, find the agent that is being forwarded messages from both.
If none exist, return nullptr.
Memory requirement: O(1)
Speed requirement: O(N)
*/
Agent* findIntersect(Agent* firstHead, Agent* secondHead) 
{
	int first = 0;
	int second = 0;
	Agent* firstSociety = firstHead;
	Agent* secondSociety = secondHead;

	while (firstSociety->nextAgent != nullptr) 
	{
		++first;
		firstSociety = firstSociety->nextAgent;
	}

	while (secondSociety->nextAgent != nullptr) 
	{
		++second;
		secondSociety = secondSociety->nextAgent;
	}

	// If there is no double crosser
	if (firstSociety->ID != secondSociety->ID)
		return nullptr;

	// From this point on, there must be one
	firstSociety = firstHead;
	secondSociety = secondHead;

	// if societies are of the same size
	if (first == second) 
	{
		while (firstSociety->nextAgent != nullptr) 
		{
			if (firstSociety->ID == secondSociety->ID) 
				return secondSociety;

			firstSociety = firstSociety->nextAgent;
			secondSociety = secondSociety->nextAgent;
		}
	}

	// if first society has more members
	else if (first > second) 
	{
		int i = first - second;
		while (i != 0) 
		{
			// these are "impossible" agents
			firstSociety = firstSociety->nextAgent;
			--i;
		}

		while (firstSociety->nextAgent != nullptr) 
		{
			if (firstSociety->ID == secondSociety->ID)
				return secondSociety;

			firstSociety = firstSociety->nextAgent;
			secondSociety = secondSociety->nextAgent;
		}
	}
	// if first society has less members
	else 
	{
		int i = second - first; 
		while (i != 0) 
		{
			// these are "impossible" agents
			secondSociety = secondSociety->nextAgent;
			--i;
		}

		while (firstSociety->nextAgent != nullptr) 
		{
			if (firstSociety->ID == secondSociety->ID)
				return secondSociety;

			firstSociety = firstSociety->nextAgent;
			secondSociety = secondSociety->nextAgent;
		}
	}
	return firstSociety;
}