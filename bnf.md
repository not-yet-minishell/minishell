```
<LIST>                  ::= <SUBLIST> '&&' <LIST>
						| <SUBLIST> '||' <LIST>
						| <PIPELIE>

<SUBLIST>				::=  '(' <LIST> ')'
							| <PIPELINE>

<SIMPLE-COMMAND>        ::= <WORD>
				        | <WORD> <SIMPLE-COMMAND>

<PIPELINE>              ::= <COMMAND>
                        | <COMMAND> '|' <PIPELINE>

<COMMAND>               ::=  <SIMPLE-COMMAND-ELEMENT>
                        |  <SIMPLE-COMMAND-ELEMENT> <COMMAND>
						| '(' <LIST> ')'

<SIMPLE-COMMAND-ELEMENT>::= <WORD>
						| <REDIRECTION>

<REDIRECTION>           ::=  '<'   <WORD>
                        |  '<<'  <WORD>
                        |  '>'   <WORD>
                        |  '>>'  <WORD>
```
