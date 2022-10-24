DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList = list<int>(); 
    logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList = list<int>(); 
    logList.push_back(data);
    currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    
    (*currentState)+=number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
     
   (*currentState)-=number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    logList.erase(next(currentState,1), logList.end());
    logList.push_back(*currentState);
    currentState++;
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
     if (currentState == logList.begin()) return;
     currentState--;
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
     if (next(currentState, 1) == logList.end()) return;
     currentState++;
}
