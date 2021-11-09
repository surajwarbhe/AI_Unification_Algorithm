# UNIFICATION ALGORITHM IN ARTIFICIAL INTELLIGENCE

### AIM: 
Implementation of Unification algorithm by considering Resolution concept.


### THEORY:
#### UNIFICATION: 
- It is a process of making two different logical atomic expressions identical by finding a substitution. 
- Unification depends on the substitution process.
- It takes two literals as input and makes them identical using substitution.
- Let Ψ1 and Ψ2 be two atomic sentences and 𝜎 be a unifier such that, Ψ1𝜎 = Ψ2𝜎, then it can be expressed as UNIFY(Ψ1, Ψ2)
```
Example: Find the MGU for Unify{King(x), King(John).
         Let Ψ1 = King(x), Ψ2 = King(John),
         Substitution θ = {John/x} is a unifier for these atoms and applying this substitution, both expressions will be identical.
 ```
 
#### CONDITION FOR UNIFICATION:
- Following are some basic conditions for unification:
- Predicate symbols must be the same, atoms or expressions with different predicate symbols can never be unified.
- Number of Arguments in both expressions must be identical.
- Unification will fail if there are two similar variables present in the same expression.
 
### ALGORITHM:

```
Step 1: If Ψ1 or Ψ2 is a variable or constant, then:
        a) If Ψ1 or Ψ2 are identical, then return NIL. 
        b) Else if Ψ1 is a variable,
              i) then if Ψ1 occurs in Ψ2, then return FAILURE
              ii) Else return { (Ψ2/ Ψ1)}.
        c) Else if Ψ2 is a variable,  
              i) If Ψ2 occurs in Ψ1 then return FAILURE,
              ii) Else return {( Ψ1/ Ψ2)}.
        d) Else return FAILURE. 

Step 2: If the initial Predicate symbol in Ψ1 and Ψ2 are not same, then return FAILURE.

Step 3: IF Ψ1 and Ψ2 have a different number of arguments, then return FAILURE.

Step 4: Set Substitution set(SUBST) to NIL. 

Step 5: For i=1 to the number of elements in Ψ1. 
      a) Call Unify function with the ith element of Ψ1 & ith element of Ψ2, & put the result into S.
      b) If S = failure then returns Failure
      c) If S ≠ NIL then do,
              i) Apply S to the remainder of both L1 and L2.
              ii) SUBST= APPEND(S, SUBST). 

Step.6: Return SUBST. 

```

### PROGRAMMING LANGUAGE: C

### OUTPUT:

#### 1. WHEN NUMBER OF ARGUMENTS ARE SAME:
```

	=========PROGRAM FOR UNIFICATION=========

Enter Number of Expressions:- [2]

Enter Expression 1:-[a]

	Enter No.of Arguments for Expression a:-[2]

	Enter argument 1:(x)

	Enter argument 2:(3)

Enter Expression 2:-[a]

	Enter No.of Arguments for Expression a:-[2]

	Enter argument 1:(k)

	Enter argument 2:(5)

	===========EXPRESSIONS==========
	a(x,3)
	a(k,5)
	==========SUBSTITUTION==========
	k/x
	5/3

Do you want to continue(y/n):   n

```

#### 2. WHEN NUMBER OF ARGUMENTS ARE NOT SAME:
```

	=========PROGRAM FOR UNIFICATION=========

Enter Number of Expressions:- [2]

Enter Expression 1:-[a]

	Enter No.of Arguments for Expression a:-[2]

	Enter argument 1:(5)

	Enter argument 2:(x)

Enter Expression 2:-[a]

	Enter No.of Arguments for Expression a:-[3]

	Enter argument 1:(6)

	Enter argument 2:(x)

	Enter argument 3:(y)

	===========EXPRESSIONS==========
	a(5,x)
	a(6,x,y)

Arguments are not Same..!

Do you want to continue(y/n): n  
```

#### 3. WHEN ARGUMENTS ARE IDENTICAL:

```

	=========PROGRAM FOR UNIFICATION=========

Enter Number of Expressions:- [2]

Enter Expression 1:-[a]

	Enter No.of Arguments for Expression a:-[2]

	Enter argument 1:(3)

	Enter argument 2:(7)

Enter Expression 2:-[a]

	Enter No.of Arguments for Expression a:-[2]

	Enter argument 1:(3)

	Enter argument 2:(7)

	===========EXPRESSIONS==========
	a(3,7)
	a(3,7)

Arguments are Identical..!

No need of Substitution !

Do you want to continue(y/n):   n

```

### CONCLUSION:
- From this assignment, we learnt the concept of Unification and Resolution concept in Artificial Intelligence.
- Also, implement the Unification problem for various case like-
    - Number of Arguments are the same
    - Number of Arguments are not the same
    - Arguments are identical
