/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "John Cat"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream ifile(filename);
  std::string name;
  std::set<std::string> s;
  while (std::getline(ifile, name)) {
    s.insert(name);
  }
  return s;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

bool is_match(char c1, char c2, std::string student_name) {
  std::stringstream ss(student_name);
  std::string first, second;
  ss >> first >> second;
  if (c1 == first[0] && c2 == second[0]) {
    return true;
  } else {
    return false;
  }
}

std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::string first, second;
  std::queue<const std::string*> q;
  std::stringstream ss(name);
  ss >> first >> second;
  for (auto &student_name : students) {
    if (is_match(first[0], second[0], student_name)) {
      q.push(&student_name);
    }
  }
  return q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  const std::string LoveName = "John";
  while (!matches.empty()) {
    if (matches.front()->find(LoveName)) {
      return *matches.front();
    }
    matches.pop();
  }
  return "NO MATCHES FOUND.";
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
