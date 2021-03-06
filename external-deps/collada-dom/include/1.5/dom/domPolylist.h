#ifndef __domPolylist_h__
#define __domPolylist_h__

#include <dae/daeDocument.h>
#include <dom/domTypes.h>
#include <dom/domElements.h>

#include <dom/domInput_local_offset.h>
#include <dom/domP.h>
#include <dom/domExtra.h>
class DAE;

/**
 * The polylist element provides the information needed to bind vertex attributes
 * together and  then organize those vertices into individual polygons. The
 * polygons described in polylist can  contain arbitrary numbers of vertices.
 * Unlike the polygons element, the polylist element cannot  contain polygons
 * with holes.
 */
class domPolylist : public daeElement
{
public:
	virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::POLYLIST; }
	static daeInt ID() { return 27; }
	virtual daeInt typeID() const { return ID(); }
public:
	class domVcount;

	typedef daeSmartRef<domVcount> domVcountRef;
	typedef daeTArray<domVcountRef> domVcount_Array;

/**
 * The vcount element contains a list of integers describing the number of
 * sides for each polygon  described by the polylist element. The vcount element
 * may occur once.
 */
	class domVcount : public daeElement
	{
	public:
		virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::VCOUNT; }
		static daeInt ID() { return 28; }
		virtual daeInt typeID() const { return ID(); }


	public:	//Accessors and Mutators
		/**
		 * Gets the value of this element.
		 * @return a domList_of_uints of the value.
		 */
		domList_of_uints& getValue() { return _value; }
		/**
		 * Sets the _value of this element.
		 * @param val The new value for this element.
		 */
		void setValue( const domList_of_uints& val ) { _value = val; }

	protected:  // Value
		/**
		 * The domList_of_uints value of the text data of this element. 
		 */
		domList_of_uints _value;
	protected:
		/**
		 * Constructor
		 */
		domVcount(DAE& dae) : daeElement(dae), _value() {}
		/**
		 * Destructor
		 */
		virtual ~domVcount() {}
		/**
		 * Overloaded assignment operator
		 */
		virtual domVcount &operator=( const domVcount &cpy ) { (void)cpy; return *this; }

	public: // STATIC METHODS
		/**
		 * Creates an instance of this class and returns a daeElementRef referencing it.
		 * @return a daeElementRef referencing an instance of this object.
		 */
		static DLLSPEC daeElementRef create(DAE& dae);
		/**
		 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
		 * If a daeMetaElement already exists it will return that instead of creating a new one. 
		 * @return A daeMetaElement describing this COLLADA element.
		 */
		static DLLSPEC daeMetaElement* registerElement(DAE& dae);
	};


protected:  // Attributes
/**
 *  The name attribute is the text string name of this element. Optional attribute.
 */
	xsToken attrName;
/**
 *  The count attribute indicates the number of polygon primitives. Required
 * attribute. 
 */
	domUint attrCount;
/**
 *  The material attribute declares a symbol for a material. This symbol is
 * bound to a material at  the time of instantiation. If the material attribute
 * is not specified then the lighting and  shading results are application
 * defined. Optional attribute. 
 */
	xsNCName attrMaterial;

protected:  // Elements
/**
 * The input element may occur any number of times. This input is a local
 * input with the  offset and set attributes. @see domInput
 */
	domInput_local_offset_Array elemInput_array;
/**
 * The vcount element contains a list of integers describing the number of
 * sides for each polygon  described by the polylist element. The vcount element
 * may occur once. @see domVcount
 */
	domVcountRef elemVcount;
/**
 * The polylist element may have zero or one p element. @see domP
 */
	domPRef elemP;
/**
 * The extra element may appear any number of times. @see domExtra
 */
	domExtra_Array elemExtra_array;

public:	//Accessors and Mutators
	/**
	 * Gets the name attribute.
	 * @return Returns a xsToken of the name attribute.
	 */
	xsToken getName() const { return attrName; }
	/**
	 * Sets the name attribute.
	 * @param atName The new value for the name attribute.
	 */
	void setName( xsToken atName ) { *(daeStringRef*)&attrName = atName;}

	/**
	 * Gets the count attribute.
	 * @return Returns a domUint of the count attribute.
	 */
	domUint getCount() const { return attrCount; }
	/**
	 * Sets the count attribute.
	 * @param atCount The new value for the count attribute.
	 */
	void setCount( domUint atCount ) { attrCount = atCount; }

	/**
	 * Gets the material attribute.
	 * @return Returns a xsNCName of the material attribute.
	 */
	xsNCName getMaterial() const { return attrMaterial; }
	/**
	 * Sets the material attribute.
	 * @param atMaterial The new value for the material attribute.
	 */
	void setMaterial( xsNCName atMaterial ) { *(daeStringRef*)&attrMaterial = atMaterial;}

	/**
	 * Gets the input element array.
	 * @return Returns a reference to the array of input elements.
	 */
	domInput_local_offset_Array &getInput_array() { return elemInput_array; }
	/**
	 * Gets the input element array.
	 * @return Returns a constant reference to the array of input elements.
	 */
	const domInput_local_offset_Array &getInput_array() const { return elemInput_array; }
	/**
	 * Gets the vcount element.
	 * @return a daeSmartRef to the vcount element.
	 */
	const domVcountRef getVcount() const { return elemVcount; }
	/**
	 * Gets the p element.
	 * @return a daeSmartRef to the p element.
	 */
	const domPRef getP() const { return elemP; }
	/**
	 * Gets the extra element array.
	 * @return Returns a reference to the array of extra elements.
	 */
	domExtra_Array &getExtra_array() { return elemExtra_array; }
	/**
	 * Gets the extra element array.
	 * @return Returns a constant reference to the array of extra elements.
	 */
	const domExtra_Array &getExtra_array() const { return elemExtra_array; }
protected:
	/**
	 * Constructor
	 */
	domPolylist(DAE& dae) : daeElement(dae), attrName(), attrCount(), attrMaterial(), elemInput_array(), elemVcount(), elemP(), elemExtra_array() {}
	/**
	 * Destructor
	 */
	virtual ~domPolylist() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domPolylist &operator=( const domPolylist &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static DLLSPEC daeElementRef create(DAE& dae);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static DLLSPEC daeMetaElement* registerElement(DAE& dae);
};


#endif
