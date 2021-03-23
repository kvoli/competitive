#include <bits/stdc++.h>
#include <condition_variable>
using namespace std;
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
  private:
  int thread_num;
  string hostname;
  queue<string> q;
  unordered_set<string> seen;
  int working = 0;
  bool done;
  mutex m;
  condition_variable cv;

  string extractHostName(string& url)
  {
    int start = url.find('/') + 2;
    int end = url.find('/', start);
    if (end == string::npos)
      return url.substr(start);
    return url.substr(start, end - start);
  }

  vector<thread> workers;

  void work(HtmlParser* parser)
  {
    while (true) {
      unique_lock<mutex> ul(m);
      cv.wait(ul, [&] { return q.size() > 0 || done; });
      if (done)
        return;
      working++;
      string item = q.front();
      q.pop();

      ul.unlock();
      auto access = parser->getUrls(item);
      ul.lock();

      for (auto& url : access) {
        if (seen.count(url) || extractHostName(url) != hostname)
          continue;
        seen.insert(url);
        q.push(url);
      }
      working--;

      if (working == 0 && q.empty())
        done = true;
      cv.notify_all();
    }
  }

  public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser)
  {
    hostname = extractHostName(startUrl);
    seen.insert(startUrl);
    done = false;

    thread_num = thread::hardware_concurrency();
    q.push(startUrl);

    for (int i = 0; i < thread_num; ++i) {
      workers.emplace(&Solution::work, this, &htmlParser);
    }

    for (auto& t : workers) {
      t.join();
    }
    return vector<string>(seen.begin(), seen.end());
  }
};
