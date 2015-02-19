# bwi_gridworld
Project for the FRI class in Autonomous Robot stream

Current status:
Working! beta .01
Agent class included has some dummy policy.
#######NOTE#######
The policy implemented by the agents will almost never find the event, so running the exe will seem as though there is an infinite loop...because there is.









This project holds the codebase for the agent-gridworld simulation!

The premise is this: There is a width x height grid in which four agents are placed.
At some point during the simulation, an event will be placed on the map. The time it takes for the first agent to be found is measured.
It is adventageous to minimize this time, which can be accomplished with optimal policies for each agent.

The GRID simulation will poll each agent for their move on each simulation step. The 'brains' of the agent is in the return method of nextMove().
How the agent knows what to return and when is a matter of policy.


## Instructions

For notational purposes we will use CSID to represent your UTCS ID.

Setting up is really easy, once you've cloned all you have to do is set the
remote location to your specified repo.  Once you push, your code will be
cloned on the server, subsequently compiled and the results will be given back
to you.


1. git clone CSID@104.236.234.64:/fri/bwi_gridworld
2. cd bwi_gridworld
3. git remote set-url origin CSID@104.236.234.64:/fri/CSID/agent.git
4. git push origin master

## Submitting

Your progress is tracked, there isn't a formal final submission. We will grade
the last submission you push before the deadline.
