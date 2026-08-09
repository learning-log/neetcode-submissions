class Twitter:

    def __init__(self):
        self.user_tweets = {}
        self.user_followings = {}
        self.ts = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        tweets = self.user_tweets.get(userId,[])
        heapq.heappush(tweets,(self.ts,tweetId))
        self.user_tweets[userId] = tweets
        sset = self.user_followings.get(userId,set())
        sset.add(userId)
        self.user_followings[userId] = sset
        self.ts +=1
        


    def getNewsFeed(self, userId: int) -> List[int]:

        friends = self.user_followings.get(userId,set())
        latest_tweets = []
        for f in friends:
            tweets = self.user_tweets.get(f,[])

            for t in tweets:
                if len(latest_tweets)< 10:
                    heapq.heappush(latest_tweets,t)
                else:
                    topt = heapq.heappop(latest_tweets)
                    if topt[0]<t[0]:
                        heapq.heappush(latest_tweets,t)
                    else:
                        heapq.heappush(latest_tweets,topt)
        ans = []
        while len(latest_tweets)!=0:
            ans.append(heapq.heappop(latest_tweets)[1])
        ans.reverse()
        return ans

        

    def follow(self, followerId: int, followeeId: int) -> None:
        if followeeId not in self.user_followings.get(followerId,set()):
            sset = self.user_followings.get(followerId,set())
            sset.add(followeeId)
            self.user_followings[followerId] = sset
        
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:
            return
        if followeeId in self.user_followings.get(followerId,set()):
            sset = self.user_followings.get(followerId,set())
            sset.remove(followeeId)
            self.user_followings[followerId] = sset
        
