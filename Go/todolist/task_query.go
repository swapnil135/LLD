package main

type TaskQuery interface {
	GetTask(key string) (TaskInterface, error)
}


var _ TaskQuery = &TaskQueryById{}

type TaskQueryById struct {
	storage TaskStorage 
}

func NewTaskQueryById(storage *ListTaskStorage) *TaskQueryById {
	return &TaskQueryById{
		storage: storage,
	}
}

func (t *TaskQueryById) GetTask(taskId string) (TaskInterface, error){
	taskList := t.storage.GetAllTasks()

	for _, task := range taskList {
		if task.GetId() == taskId {
			return task, nil
		}
	}

	return nil, ErrorRecordNotFound
}