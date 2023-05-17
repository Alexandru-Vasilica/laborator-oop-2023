#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include"CircularQueue.h"
#include<string>

 
   TEST_CASE("Size returned correctly", "[size]") {
    CircularQueue<std::string> q(4);
       q.push("UNU");
    q.push("DOI");
    REQUIRE(q.size() == 2);
}
   TEST_CASE("Empty returned correctly", "[empty]") {
    CircularQueue<std::string> q(4);
    q.push("UNU");
    q.pop();
    REQUIRE(q.empty());
   }
   TEST_CASE("Front and Back exception", "[exception]") {
    CircularQueue<std::string> q(4);
    REQUIRE_THROWS(q.front());
    REQUIRE_THROWS(q.back());
   }
   TEST_CASE("Circular property works", "[circular]") {
    CircularQueue<unsigned> q(4);
    for (unsigned i = 1; i <= 5; i++)
        q.push(i);
    REQUIRE(q.front() == 5);
  
   }
   TEST_CASE("Circular property works 2", "[circular]") {
    CircularQueue<unsigned> q(4);
    for (unsigned i = 1; i <= 1000; i++)
        q.push(i);
    REQUIRE(q.pop() == 997);
    REQUIRE(q.pop() == 998);
    REQUIRE(q.pop() == 999);
    REQUIRE(q.pop() == 1000);
    for (unsigned i = 1; i <= 996; i++)
        REQUIRE_THROWS(q.pop());
   }
   TEST_CASE("Pop exception", "[exception]") {
    CircularQueue<std::string> q(4);
    REQUIRE_THROWS(q.pop());
   }
   TEST_CASE("Check max size", "[size]") {
    CircularQueue<unsigned> q(4);
    for (unsigned i = 1; i <= 10; i++)
        q.push(i);
    REQUIRE(q.size() == 4);
   }