s/\b[a-zA-Z]\{3\}[0-9]\{3\}\b/XYZ123/
s/@[0-9]\{8\}\b/@XXXXXXXX/
s/\b[0-4].[0-9]\{1,3\}\b/ X.X/
s/\b[ABCDFabcdf]\{1\}[+-]\?\b/X/
/^[Xx]/d