#include <bits/stdc++.h>

using namespace std;

// Post Content: Users can post new content (text, images, videos).
// Like Content: Users can like posts.
// Comment on Content: Users can comment on posts.
// Search Content: Users can search for posts by keyword, author, or date.

class User {
    private:
    string id;

    public:
    User(string id)
    :id(id){}

    string GetId(){
        return id;
    }
};

class Post {
    public:
    virtual string GetContent() = 0;
    virtual void LikePost(string likerUserId) = 0;
    virtual void CommentPost(string commenterId, string comment) = 0; 
};

class TextPost {
    public:
    string id
}