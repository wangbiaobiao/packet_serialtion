for i in root.childNodes:
	if i.localName == 'messageDefinition':
		print i
		for j in i.childNodes:
			if j.localName == 'field':
				print j.localName
