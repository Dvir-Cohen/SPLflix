#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Watchable;
class Session;

class User{
public:
    User(const std::string& name);
    User(const User& other);// copy constructor
    User(User &&other);// Move constructor
    User& operator=(const User &other); //Copy Assigment
    User& operator=(User&& other); //Move Assigment

    virtual Watchable* getRecommendation(Session& ) = 0;
    std::string getName() const;
    std::vector<Watchable*> get_history() const;
    std::string getType();
    void setType(std::string str);
    void addHist(Watchable* wat);
    void printHist();
    //Distructor
    virtual ~User();
    virtual User* clone()=0;
protected:
    std::vector<Watchable*> history;
private:
    const std::string name;
    std::string type;

};


class LengthRecommenderUser : public User{
public:
    LengthRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone();

private:
};

class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone();
private:
    int i;
};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(const std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone();
private:
};

#endif
