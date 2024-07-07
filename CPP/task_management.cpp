// Create Tasks: Users can create new tasks with a title, description, and due date.
// Update Tasks: Users can update the title, description, and due date of existing tasks.
// Delete Tasks: Users can delete tasks.
// Search Tasks: Users can search for tasks by title or due date.

#include <bits/stdc++.h>

using namespace std;


class TaskI {
    public:
     virtual string GetDueDate() = 0;
     virtual string GetTitle() = 0;
};

class SimpleTask:TaskI {
    private:
    string title;
    string dueDate;

    public:
    SimpleTask(string title, string dueDate){
        this->title = title;
        this->dueDate = dueDate;
    }

    string GetTitle(){
        return this->title;
    }

    string GetDueDate(){
        return this->dueDate;
    }
};

class TaskStorage {
    private:
    unordered_map<string, vector<TaskI*>> dueDateMap;
    unordered_map<string, vector<TaskI*>> titleMap;

    public:
    void AddTask(TaskI* task){
        dueDateMap[task->GetDueDate()].push_back(task);
        titleMap[task->GetTitle()].push_back(task);
    }

    unordered_map<string, vector<TaskI*>> GetDueDateMap(){
        return dueDateMap;
    }

    unordered_map<string, vector<TaskI*>> GetTitleMap(){
        return titleMap;
    }
};

class TaskSearcher {
    public:
    virtual vector<TaskI*> SearchTask(TaskStorage* storage, string key) = 0;
};

class SearcherByDueDate:TaskSearcher{
    public:
    vector<TaskI*> SearchTask(TaskStorage* storage, string dueDate){
        return storage->GetDueDateMap()[dueDate];
    }
};

class SearcherByTitle:TaskSearcher{
    public:
    vector<TaskI*> SearchTask(TaskStorage* storage, string title){
        return storage->GetTitleMap()[title];
    }
};