```
<LIST>                  ::=  <SUBLIST> '&&' <SUBLIST>
                        | <SUBLIST> '||' <SUBLIST>
                        | <PIPELINE>

<SUBLIST>               ::= '(' <LIST> ')'
		            	| <SIMPLE-COMMMAND>

<SIMPLE-COMMAND>        ::= <WORD>
				        | <WORD> <SIMPLE-COMMAND>

<PIPELINE>              ::= <COMMAND>
                        | <COMMAND> '|' <PIPELINE>

<COMMAND>               ::=  <SIMPLE-COMMAND-ELEMENT>
                        |  <SIMPLE-COMMAND-ELEMENT> <COMMAND>

<SIMPLE-COMMAND-ELEMENT>::= <WORD>
						| <REDIRECTION>

<REDIRECTION>           ::=  '<'   <WORD>
                        |  '<<'  <WORD>
                        |  '>'   <WORD>
                        |  '>>'  <WORD>
```
