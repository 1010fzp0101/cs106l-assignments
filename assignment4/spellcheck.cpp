#include "spellcheck.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <string>
#include <system_error>
#include <vector>

namespace rv = std::ranges::views; 


template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  auto boundaries = find_all(source.begin(), source.end(), ::isspace);
  Corpus corpus;
  std::transform(boundaries.begin(), boundaries.end() - 1, boundaries.begin() + 1, std::inserter(corpus, corpus.end()),
  [&source](auto it1, auto it2) -> Token { return Token(source, it1, it2); });
  std::erase_if(corpus, [corpus](const Token &token) { return token.content.empty(); });
  return corpus;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  auto view = source | rv::filter([&dictionary](auto token){
    return !dictionary.contains(token.content);
  }) | rv::transform([&dictionary](auto token) {
    auto view = dictionary | rv::filter([&dictionary, &token](auto word){
      return levenshtein(word, token.content) == 1;
    });
    std::set<std::string> suggestion(view.begin(), view.end());
    return Misspelling {token, suggestion};
  }) | rv::filter([](auto ms){
    return ms.suggestions.size() > 0;
  });
  std::set<Misspelling> sM(view.begin(), view.end());
  return sM;
}

/* Helper methods */

#include "utils.cpp"