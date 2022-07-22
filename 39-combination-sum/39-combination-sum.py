class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans=[[] for i in range(target)]
        for i in range(len(candidates)):
            for j in range(target):
                if j+1-candidates[i]==0:
                    ans[j].append({j+1:1})
                if j-candidates[i]>=0:
                    for x in ans[j-candidates[i]]:
                        tmp=dict()
                        for y in x:
                            if y==candidates[i]:
                                tmp[y]=x[y]+1
                            else:
                                tmp[y]=x[y]
                        if candidates[i] not in tmp:
                            tmp[candidates[i]]=1
                        ans[j].append(tmp)
        a=[]
        for x in ans[target-1]:
            tmp=[]
            for y in x:
                for i in range(x[y]):
                    tmp.append(y)
            a.append(tmp)
        return a