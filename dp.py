def countConstruct(s, words, memo):
  if s in memo:
    return memo[s]
  if s=="":
    return 1
  
  totCount=0

  for word in words:
    if s.startswith(word):
      val=countConstruct(s[len(word):], words, memo)
      totCount+=val
  
  memo[s]=totCount
  return memo[s]
  


def canConstruct(s, words, memo):
  if s in memo:
    return memo[s]
  if s=="":
    return True
  for word in words:
    if s.startswith(word):
      if canConstruct(s[len(word):], words, memo) == True:
        memo[s] = True
        return memo[s]

  memo[s]=False
  return memo[s]



def howSum(target, numbers, memo):
  if target in memo:
    return memo[target]
  if target == 0:
    return []
  if target<0:
    return None
  shortest = None

  for i in numbers:
    sum=howSum(target-i, numbers, memo)    
    if sum!=None:
      memo[target]=sum+[i]
      if shortest==None or len(shortest)>len(memo[target]):
        shortest = memo[target]

  memo[target]= shortest
  return memo[target]



def canSum(target, numbers, memo):
  if  target in memo:
    return memo[target]
  if target==0:
    return True
  if target<0:
    return False
  
  for i in numbers:
    if canSum(target-i, numbers, memo)==True:
      memo[target]=True
      return True
  memo[target]=False
  return False