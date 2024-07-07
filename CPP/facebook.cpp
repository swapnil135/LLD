// Design Facebook
// Let users add friends
// Let users add posts
// User should be able to get the last 10 posts by their friends
// Let users comment/like on a post.

#include <bits/stdc++.h>

using namespace std;

class Facebook {
    private:
    map<string, User> UserMap; 

};

class User {
    private:
    string id;
    string userName;
    vector<Post> posts;
    map<string, bool> friends;

};

// can make this an interface and let text/vid/photo post implement it.
class Post {
    private:
    string userId;
    string content;
    set<Like*> likes;
    vector<Comment*> comments;
};

class Comment {
    private:
    string byUser;
    string postId;
    string content;
};

class Like {
    private:
    string byUserId;
    string postId;

};