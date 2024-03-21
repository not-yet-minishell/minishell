```
<LIST>          ::= <SUBLIST> '&&' <LIST>
				| <SUBLIST> '||' <LIST>
                | <SUBLIST>

<SUBLIST>       ::= '(' <LIST> ')'
				| <PIPELINE>

<PIPELINE>      ::= <COMMAND>
                | <COMMAND> '|' <PIPELINE>

<COMMAND>       ::=  <SIMPLE-COMMAND>
                |  <SIMPLE-COMMAND> <COMMAND>

<SIMPLE-COMMAND>::= <WORD>
				| <REDIRECTION>

<REDIRECTION>   ::= '<'   <WORD>
                |  '<<'  <WORD>
                |  '>'   <WORD>
                |  '>>'  <WORD>
```
